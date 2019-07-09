package main

import "fmt"
import "time"

func main() {
	cells := [][]int{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}
	printCells(cells)
	execute(cells)
}

func printCells(cells [][]int) {
	for _, items := range cells {
		fmt.Printf("%v\n", items)
	}
}

func execute(cells [][]int) {
	printCells(cells)
	nextCells := getNextCells(cells)
	time.Sleep(1000000000)
	fmt.Printf("\n")
	execute(nextCells)
}

func getNextCells(cells [][]int) [][]int {
	new := [][]int{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}
	for _, i := range []int{1, 2, 3} {
		for _, j := range []int{1, 2, 3} {
			new[i][j] = boolToInt(countLivingCell(cells, i, j, 0) == 3 || (countLivingCell(cells, i, j, 0) == (3 - boolToInt((cells[i][j] == 1)))))
		}
	}
	return new
}

func boolToInt(flag bool) int {
	if flag {
		return 1
	}
	return 0
}

func countLivingCell(cells [][]int, i int, j int, cnt int) int {
	for _, k := range []int{-1, 0, 1} {
		for _, l := range []int{-1, 0, 1} {
			cnt += cells[i+k][j+l]
		}
	}
	return cnt - cells[i][j]
}
