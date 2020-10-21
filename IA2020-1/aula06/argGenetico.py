numberTest = int(input())
result = []

for i in range(numberTest):
    numberBits = int(input())
    positionCut = int(input())
    probability = float(input())
    firstIndividual = []
    secondIndividual = []
    comparing = []
    newPopulationOne = []
    newPopulationTwo = []
    kiPopulationOne = []
    kiPopulationTwo = []
    probArrayOne = []
    probArrayTwo = []

    for i in range(numberBits):
        ele = int(input())
        firstIndividual.append(ele)

    for i in range(numberBits):
        ele = int(input())
        secondIndividual.append(ele)

    for i in range(numberBits):
        ele = int(input())
        comparing.append(ele)

    def crossover(popOne, popTwo, positionCut):
        for i in range(positionCut):
            newPopulationOne.append(popOne[i])
            newPopulationTwo.append(popTwo[i])

        for i in range(positionCut,numberBits):
            newPopulationOne.append(popTwo[i])
            newPopulationTwo.append(popOne[i])

    def calculateKiOne(population, comparing):
        for i in range(numberBits):
            if population[i] == comparing[i]:
                kiPopulationOne.append(0)
            else:
                kiPopulationOne.append(1)

    def calculateKiTwo(population, comparing):
        for i in range(numberBits):
            if population[i] == comparing[i]:
                kiPopulationTwo.append(0)
            else:
                kiPopulationTwo.append(1)


    def arrayProbabilityOne(kiPopulation, probArrayOne, probability):
        for i in range(numberBits):
            if kiPopulation[i] == 1:
                probArrayOne.append(1-probability)
            else: 
                probArrayOne.append(probability)

    def arrayProbabilityTwo(kiPopulationTwo, probArrayTwo, probability):
        for i in range(numberBits):
            if kiPopulationTwo[i] == 1:
                probArrayTwo.append(probability)
            else: 
                probArrayTwo.append(1-probability)

    def probabilityChild(prob):
        proba = prob[0]
        for i in range(numberBits):
            proba = proba * prob[i]
        return proba

    def probabilityFinal(probArrayOne, probArrayTwo, result):
        result.append((probabilityChild(probArrayOne) + probabilityChild(probArrayTwo)) - (probabilityChild(probArrayOne) * probabilityChild(probArrayTwo)))

    crossover(firstIndividual, secondIndividual, positionCut)
    calculateKiOne(newPopulationOne, comparing)
    calculateKiTwo(newPopulationTwo, comparing)
    arrayProbabilityOne(kiPopulationOne, probArrayOne, probability)
    arrayProbabilityTwo(kiPopulationTwo, probArrayTwo, probability)
    probabilityChild(probArrayOne)
    probabilityChild(probArrayTwo)
    probabilityFinal(probArrayOne, probArrayTwo, result)
    

for i in range(numberTest):
    print('{0:.7f}'.format(result[i]))