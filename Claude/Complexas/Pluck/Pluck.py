def pluck_matrix(coordinates):
    remaining = set(coordinates)
    plucks = 0
    
    while remaining:
        best_pluck = max(remaining, key=lambda coord: len(get_affected(coord) & remaining))
        remaining -= get_affected(best_pluck)
        plucks += 1
    
    return plucks

def get_affected(coord):
    i, j = coord
    return {(i-1, j), (i, j-1), (i, j), (i, j+1), (i+1, j)}

# Example usage
coordinates = {(0, 0), (0, 1), (1, 0), (1, 1), (2, 2)}
print(f"Minimum plucks required: {pluck_matrix(coordinates)}")