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

def get_combinations_by_removing_one_level(report):
    return [report[:i] + report[i+1:] for i in range(len(report))]

num_safe_reports = 0
for report in reports:
    if is_safe(report):
        num_safe_reports += 1
    else:
        combinations = get_combinations_by_removing_one_level(report)
        for combination in combinations:
            if is_safe(combination):
                num_safe_reports += 1
                break 

print('Number of safe reports:', num_safe_reports)
        
