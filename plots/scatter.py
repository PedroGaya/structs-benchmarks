import matplotlib.pyplot as plt
import matplotlib.lines as mlines

import numpy as np
import math as m

from os import path


basepath = path.dirname(__file__)

abp_c_r = path.abspath(path.join(basepath, "../logs/abp_benchmarks/consult/random.txt"))
abp_c_o = path.abspath(path.join(basepath, "../logs/abp_benchmarks/consult/ordered.txt"))
abp_i_r = path.abspath(path.join(basepath, "../logs/abp_benchmarks/insert/random.txt"))
abp_i_o = path.abspath(path.join(basepath, "../logs/abp_benchmarks/insert/ordered.txt"))

lsec_c_r = path.abspath(path.join(basepath, "../logs/lsec_benchmarks/consult/random.txt"))
lsec_c_o = path.abspath(path.join(basepath, "../logs/lsec_benchmarks/consult/ordered.txt"))
lsec_i_r = path.abspath(path.join(basepath, "../logs/lsec_benchmarks/insert/random.txt"))
lsec_i_o = path.abspath(path.join(basepath, "../logs/lsec_benchmarks/insert/ordered.txt"))

paths = [abp_c_r, lsec_c_r, abp_i_r, lsec_i_r, abp_i_o, lsec_c_o, lsec_i_o, abp_c_o]

def parse_line(string: str) -> np.ndarray:
    values = map(int, string.split("|"))

    return np.array(list(values))

def parse_data(path: str) -> np.ndarray:
    values = []

    with open(path, 'r') as file:
        for line in file.readlines():
            array = parse_line(line)
            values.append(array)
    
    return np.array(values)

# parse_data retorna um ndarray, onde cada elemento do ndarray (array) é outro ndarray (elemento).
# elemento[0] é sempre o tamanho do banco de dados que gerou os dados.
# elemento[-1] é sempre a quantidade de operações executadas durante a inserção/consulta.
# os outros membros do elemento[] são dados sobre a duração (em ms) da inserção/consulta.

abp_c_o_data = parse_data(abp_c_o)
abp_c_r_data = parse_data(abp_c_r)
abp_i_o_data = parse_data(abp_i_o)
abp_i_r_data = parse_data(abp_i_r)
lsec_c_o_data = parse_data(lsec_c_o)
lsec_c_r_data = parse_data(lsec_c_r)
lsec_i_o_data = parse_data(lsec_i_o)
lsec_i_r_data = parse_data(lsec_i_r)

abp_c_o_mapped = np.array(list(map(lambda element: [element[0], element[2], element[-1]], abp_c_o_data)))
lsec_c_o_mapped = np.array(list(map(lambda element: [element[0], element[2], element[-1]], lsec_c_o_data)))

fig, ax = plt.subplots()

def pre_process(data):
    return np.array(list(map(lambda x: [x[1]+1, x[2]], data)))

def make_scatter(raw_data, color, marker='o'):
    plot_data = pre_process(raw_data)
    x, y = plot_data.T

    sizes = []
    def switch(x):
        return {
            100: 50,
            1000: 50,
            5000: 100,
            10000: 200,
            100000: 300,
            1000000: 400
        }[x]
    
    for element in raw_data:
        sizes.append(switch(element[0]))
    
    scatter = ax.scatter(x, y, sizes, color, marker, alpha=0.6)
    return scatter

ax.grid(True)

scatter1 = make_scatter(abp_i_r_data,'#D90000', 'v')
scatter2 = make_scatter(abp_c_r_data,'#D90000', 'o')

scatter3 = make_scatter(abp_c_o_mapped,'#D9A600', 'o')
scatter4 = make_scatter(abp_i_o_data,'#D9A600', 'v')

scatter5 = make_scatter(lsec_c_r_data,'#0000D9', 'o')
scatter6 = make_scatter(lsec_i_r_data,'#0000D9', 'v')

scatter7 = make_scatter(lsec_c_o_mapped,'#38C229', 'o')
scatter8 = make_scatter(lsec_i_o_data,'#38C229', 'v')

ax.set_ylabel('Operations')
ax.set_xlabel('Time (ms)')

ax.set_yscale('log')
ax.set_xscale('log')

random_abp_legend = mlines.Line2D([], [], color='#D90000', marker='o', linestyle='None',
                          markersize=10, label='Random ABP data.')
ordered_abp_legend = mlines.Line2D([], [], color='#D9A600', marker='o', linestyle='None',
                          markersize=10, label='Ordered ABP data')
random_lsec_legend = mlines.Line2D([], [], color='#0000D9', marker='o', linestyle='None',
                          markersize=10, label='Random LSEC data')
ordered_lsec_legend = mlines.Line2D([], [], color='#38C229', marker='o', linestyle='None',
                          markersize=10, label='Ordered LSEC data')

first_legend = plt.legend(handles=[
    random_abp_legend, ordered_abp_legend, random_lsec_legend, ordered_lsec_legend], loc="upper left")

plt.gca().add_artist(first_legend)


arrow_legend = mlines.Line2D([], [], color='#575757', marker='v', linestyle='None',
                          markersize=10, label='Inserts')
circle_legend = mlines.Line2D([], [], color='#575757', marker='o', linestyle='None',
                          markersize=10, label='Consults')
                        
plt.legend(handles=[arrow_legend, circle_legend], loc="lower right")

plt.title("Todos os dados.")

plt.show()

