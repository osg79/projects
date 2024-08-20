"""
Lists and Tuples
"""
# lists are mutable
list_1 = ['A', 'B', 'C', 'D']
print(list_1)
list_1.append('E')
print(list_1)
list_1.pop()
print(list_1)
list_1.reverse()
print(list_1)
list_1.sort()
print(list_1)
list_1.insert(4, 'E')
print(list_1)
list_2 = ["BMW", 3, "Series"]
print(list_2[2])

# Tuples are immutable
tuple_1 = (1, 2, 3, 4, 5)
print(tuple_1)
tuple_2 = ("BMW",)
print(tuple_2)