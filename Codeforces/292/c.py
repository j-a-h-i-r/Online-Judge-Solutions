n = int(input())
digits = list(input())

digits = filter(lambda x: x not in ('0', '1'), digits)


digit_map = {
    '1': [1],
    '2': [2],
    '3': [3],
    '4': [3, 2, 2],
    '5': [5],
    '6': [3, 5],
    '7': [7],
    '8': [7, 2, 2, 2],
    '9': [7, 3, 3, 2]
}

new_number_digits = []

for digit in digits:
    new_number_digits.extend(digit_map[digit])

new_number_digits.sort(reverse=True)
# print(new_number_digits)
print("".join(map(str, new_number_digits)))