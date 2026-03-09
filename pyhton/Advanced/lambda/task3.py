s = input("something")
result = (lambda x:''.join(ch for ch in x if not('й'<ch<='я')))(s)
print(result)