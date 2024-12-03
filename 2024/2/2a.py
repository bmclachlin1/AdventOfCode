reports = []

with open('input.txt') as fin:
    for line in fin.readlines():
        report = line.split()
        reports.append([int(ch) for ch in report])

def is_all_increasing(report):
    return all(b > a and b - a <= 3 for a, b in zip(report, report[1:]))

def is_all_decreasing(report):
    return all(a > b and a - b <= 3 for a, b in zip(report, report[1:]))

def is_safe(report):
    return is_all_increasing(report) or is_all_decreasing(report)

num_safe_reports = sum(is_safe(report) for report in reports)
print('Number of safe reports:', num_safe_reports)