import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("sim_output.csv")  # adjust path if it's not next to this script

fig, axes = plt.subplots(3, 1, figsize=(8, 10), sharex=True)

axes[0].plot(df["t"], df["pos_x"], label="x")
axes[0].plot(df["t"], df["pos_y"], label="y")
axes[0].plot(df["t"], df["pos_z"], label="z")
axes[0].set_ylabel("Position (m)")
axes[0].legend()

axes[1].plot(df["t"], df["vel_x"], label="vx")
axes[1].plot(df["t"], df["vel_y"], label="vy")
axes[1].plot(df["t"], df["vel_z"], label="vz")
axes[1].set_ylabel("Velocity (m/s)")
axes[1].legend()

axes[2].plot(df["t"], df["roll"], label="roll")
axes[2].plot(df["t"], df["pitch"], label="pitch")
axes[2].plot(df["t"], df["yaw"], label="yaw")
axes[2].set_ylabel("Orientation (rad)")
axes[2].set_xlabel("Time (s)")
axes[2].legend()

plt.tight_layout()
plt.savefig("sim_plot.png")
plt.show()