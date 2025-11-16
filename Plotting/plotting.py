import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("tests.csv")

sizes = df["size"]

def plot_compare(x, y1, y2, title, ylabel="Время работы (мс)"):
    plt.figure(figsize=(12, 6))
    plt.plot(x, y1, label="Merge Sort", linewidth=2)
    plt.plot(x, y2, label="Hybrid Merge+Insertion Sort", linewidth=2)
    plt.title(title)
    plt.xlabel("N")
    plt.ylabel(ylabel)
    plt.grid(True)
    plt.legend()
    plt.show()

# Random arrays
plot_compare(
    sizes,
    df["merge_random"],
    df["hybrid_random"],
    "Сравнение времени работы на случайных массивах"
)

# Backwards sorted arrays
plot_compare(
    sizes,
    df["merge_reverse"],
    df["hybrid_reverse"],
    "Сравнение времени работы на массивах, отсортированных в обратном порядке"
)

# Almost sorted arrays
plot_compare(
    sizes,
    df["merge_almost"],
    df["hybrid_almost"],
    "Сравнение времени работы на почти отсортированных массивах"
)
