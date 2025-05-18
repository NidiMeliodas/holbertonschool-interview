#!/usr/bin/python3
import sys
import re

def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for code in sorted(status_counts):
        print("{}: {}".format(code, status_counts[code]))

def main():
    total_size = 0
    status_counts = {}
    count = 0
    valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}

    # Regex to parse lines of the exact format
    # Example line:
    # 123.123.123.123 - [2025-05-18 12:00:00] "GET /projects/260 HTTP/1.1" 200 123
    log_pattern = re.compile(
        r'^(\d{1,3}(?:\.\d{1,3}){3}) - \[[^\]]+\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = log_pattern.match(line)
            if match:
                status_code = match.group(2)
                file_size = match.group(3)

                # Only count if status code is a valid integer and in valid_status_codes
                try:
                    status_code_int = int(status_code)
                    file_size_int = int(file_size)
                except ValueError:
                    # Skip line if not valid integers
                    continue

                if status_code_int in valid_status_codes:
                    total_size += file_size_int
                    status_counts[status_code_int] = status_counts.get(status_code_int, 0) + 1
                    count += 1

                    if count % 10 == 0:
                        print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        # Print stats on keyboard interrupt as well
        print_stats(total_size, status_counts)
        raise

    # Print stats at the end if not already printed for last partial batch
    if count % 10 != 0:
        print_stats(total_size, status_counts)

if __name__ == "__main__":
    main()
