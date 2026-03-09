import pickle

#loading the list of the European city binary file
with open("file.bin", "rb") as file:
    cities = pickle.load(file)

#vowels in use here
vowels = "aeiouy"
#this thing stores cities that store filters
filtered = []

#checking the city against the hints
for city in cities:
    #hint number 1. The city must contain one uppercase letter
    upper_count = 0
    for letter in city:
        if letter.isupper():
            upper_count += 1
    # If not exactly one uppercase letter, skip this city
    if upper_count != 1:
        continue
    #first and last letters must match
    if city[0].lower() != city[-1].lower():
        continue
    #second and second to last letters must match
    if len(city) < 2:
        continue
    if city[1].lower() != city[-2].lower():
        continue
    #those letters (the 2nd/2nd-to-last) must be vowels
    if city[1].lower() not in vowels:
        continue
    #the city name must contain the letter w
    if "w" not in city.lower():
        continue
    # If the city passed all checks
    filtered.append(city)

# Print how many cities remain after all filters
print(len(filtered))

#choose the city with the shortest name among the remaining ones
shortest_city = filtered[0]
for city in filtered:
    if len(city) < len(shortest_city):
        shortest_city = city

#Save the resulting city name into letter.pickle as a binary pickle file
with open("letter.pickle", "wb") as file:
    pickle.dump(shortest_city, file)
