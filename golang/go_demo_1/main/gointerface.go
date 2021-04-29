package main

import (
	"fmt"
	"math"
)

type geo interface {
	area() float64
	perim() float64
}
type rect struct {
	width, height float64
}

type circle struct {
	radius float64
}

func (r rect) area() float64 {
	return r.height * r.width
}

func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func (r rect) perim() float64 {
	return 2*r.height + 2*r.width
}

func (c circle) perim() float64 {
	return 2 * math.Pi * c.radius
}

func measure(g geo) {
	fmt.Println(g)
	fmt.Println(g.area())
	fmt.Println(g.perim())
}

func main() {
	r := rect{width: 20, height: 30}
	c := circle{radius: 20}
	measure(r)
	measure(c)
}
