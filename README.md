# Project-CoppeliaSim
Neste projeto, uso a API [CoppeliaSim](https://www.coppeliarobotics.com/) para em uma simulação controlar um Niryo One (Braço mecânico de 6 eixos), a fim de inserir 
determinados números lidos de um arquivo .txt em uma urna e votar. 

# Objetivos
* __Ler um arquivo .txt__
* __Conectar a API de forma remota e controlar o Niryo One__
* __Certificar de que o braço mecânico aperte os números corretos e depois confirme na urna__
* __Retornar a posição inicial, finalizar a conexão e fechar o arquivo lido__

# Desenvolvimento
Tecnicamente o desenvolvimento do projeto não foi complicado, porém como não escolhi desenvolver-lo a partir da cinemática inversa, muitas tentativas e erros tiveram de 
ser feitas. Progredi muito a partir de laços e strings. Isso facilitou a construção, pois não precisei estar convertendo números para inteiros ou alocando memória, já que
poderia realizar laços quantas vezes quisesse a partir de um simples "strlen" na linha armazenada dentro de uma variável. Ao finalizar o laço que iria ler os números da 
linha inteira, apenas movimentava o braço mecânico até o voto de confirmar. Vale lembrar que estão sendo usados dois laços, um para ler caractere por caractere de uma
única linha, e outro laço para finalizar o programa quando todas as linhas forem lidas, também conhecido como !feof(arquivo). Após isso retorno todas as juntas para suas
posições zero.

# Desafios
Como citado anteriormente, como não usei cinemática inversa, tive que testar várias e várias vezes radianos com pequenas diferenças até que encontrasse o botão na posição
correta, além de que esta posição não poderia apertar outros botões. Como minha posição inicial para clicar nos números eram próximas a urna, tive diversos problemas com
isso, mas com diversas tentativas pude corrigir estes erros com o auxílio da precisão dos radianos.

# Resultado
Por fim, este foi o resultado da simulação do projeto:

https://user-images.githubusercontent.com/100333063/230750007-23725b71-0a9e-4f75-9c10-42383b2f1ce3.mp4

