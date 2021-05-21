import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()

ax.grid(True)

labels = ['1000', '5000', '10000', '1000000']
abp = [15003, 30003, 300003, 3000003]
lsec = [15003, 30003, 300003, 3000003]

x = np.arange(len(labels)) 
width = 0.35

rects1 = ax.bar(x - width/2, abp, width, label='ABP')
rects2 = ax.bar(x + width/2, lsec, width, label='LSEC')

ax.set_ylabel('Ordered Consults')
ax.set_xlabel('Data size')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()

ax.bar_label(rects1, padding=3)

ax.set_yscale("log")

fig.tight_layout()

plt.savefig("consultas3.png")
plt.show()