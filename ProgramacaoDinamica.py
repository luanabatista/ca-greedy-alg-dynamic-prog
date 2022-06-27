# Programação Dinâmica baseada em Python
# Programa para o problema da Mochila booleana
# Retorna o valor máximo possível dentro de uma mochila com capacidade W

import sys

def mochila(cap, p, val, n):
    K = [[0 for x in range(cap + 1)] for x in range(n + 1)]
  
    # Constroi uma tabela K[][] de baixo pra cima
    for i in range(n + 1):
        for w in range(cap + 1):
            if i == 0 or cap == 0:
                K[i][w] = 0
            elif p[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-p[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
  
    return K[n][cap]
  
# Seção que pede os valores de cada parametro ao usuario, e logo após exibe o resultado.
print("\n*******************************PROBLEMA DA MOCHILA BOOLEANA*******************************\n")

sys.stdout.write("Digite 3 valores: \n")
num1 = input("")
num2 = input("")
num3 = input("")

print("\n---------------------------------------------------------------------------------------------\t")

sys.stdout.write("Digite 3 pesos para cada valor: \n")
num4 = input("")
num5 = input("")
num6 = input("")

print("\n---------------------------------------------------------------------------------------------")

print("Digite a capacidade total da mochila: \n")
num7 = input("")

val = [int(num1), int(num2), int(num3)]
p = [int(num4), int(num5), int(num6)]
cap = int(num7)
n = len(val)

print("\n*******************************RESULTADO*******************************\n")
print("O valor obtido é: ", mochila(cap, p, val, n))

