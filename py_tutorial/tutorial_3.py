"""
Strings, slicing, and string functions
"""

str_1 = "This is an example"
str_2 = "UPPER CASE STRING"
str_3 = "lower case string"

print(len(str_1), len(str_2), len(str_3))

print(str_1[0:4])
print(str_2[0:5:2])
print(str_3[::])
print(str_3[::-1])
print(str_3[::-2])
print(str_3[-6:17])

print(str_2.lower())
print(str_3.upper())
print(str_1.find("an"))