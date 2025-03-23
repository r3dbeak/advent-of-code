import numpy as np
import matplotlib.pyplot as plt
import itertools

with open("input/day08.in") as file:
    grid = np.array([list(line.strip()) for line in file])

antennaSymbols = [i for i in np.unique(grid.flatten()) if i != "."]
antennaPositions = {i: list(zip(*np.where(grid == i))) for i in antennaSymbols}

seen = np.zeros(grid.shape)  # Antennas = -1, Antinodes = 1, Empty = 0
for antennaSymbol in antennaSymbols:
    for pos in antennaPositions[antennaSymbol]:
        seen[tuple(pos)] = -1
        pass

for antennaSymbol in antennaSymbols:
    for pos1, pos2 in itertools.permutations(antennaPositions[antennaSymbol], 2):
        dist = np.array(pos2) - np.array(pos1)
        for k in [-1, 1]:
            new_pos = pos1 + k * dist
            while np.all(0 <= new_pos) and np.all(new_pos < grid.shape):
                seen[tuple(new_pos)] = 1
                new_pos += dist

print(f"Result: {np.sum(seen)}")
plt.imshow(seen, cmap="winter")
plt.show()  # Image yay
