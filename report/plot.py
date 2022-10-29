import matplotlib.pyplot as plt
import pandas as pd
import sys

filename = sys.argv[1]

df = pd.DataFrame(pd.read_csv(filename))

df.plot(kind='bar')
plt.show()