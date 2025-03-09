import matplotlib.pyplot as plt

def cross_product(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

def convex_hull(points):
    points = sorted(points)
    
    lower = []
    for p in points:
        while len(lower) >= 2 and cross_product(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
    
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross_product(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
    
    return lower[:-1] + upper[:-1]

def main():
    n = int(input("Enter the number of points: "))
    points = []
    for i in range(n):
        x, y = map(int, input(f"Enter coordinates of point {i+1} (x y): ").split())
        points.append((x, y))
    
    hull = convex_hull(points)
    
    print("Convex Hull:")
    for x, y in hull:
        print(f"({x}, {y})")
    
    # Visualization
    x_vals, y_vals = zip(*points)
    plt.scatter(x_vals, y_vals, label="Input Points")
    hull.append(hull[0])  # Close the hull
    hx_vals, hy_vals = zip(*hull)
    plt.plot(hx_vals, hy_vals, "r--", label="Convex Hull")
    plt.legend()
    plt.show()

if __name__ == "__main__":
    main()
