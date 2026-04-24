solar_system = {
    "Mercury": 0.05,
    "Venus": 0.86,
    "Earth": 1,
    "Mars": 0.15,
    "Jupiter": 1321,
    "Saturn": 764,
    "Uranus": 63,
    "Neptune": 57.7,
    "Pluto": 0.059
}

solar_system.pop("Pluto")

print("Planets that are larger than Earth: ")
for planet, volume in solar_system.items():
    if volume > 1:
        print(planet)

print("\nAmount of planets starting with letter M:")
for planet, volume in solar_system.items():
    if planet.startswith("M"):
        print(volume)
