package main

import (
	"fmt"
	"time"
)

func main() {

	i := 1
	switch i {
	case 1:
		fmt.Println(1)
	case 2:
		fmt.Println(2)
	}
	switch time.Now().Weekday() {
	case time.Saturday, time.Sunday:
		fmt.Println("今天休息")
	default:
		fmt.Println("今天工作 --苦逼")
	}
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("现在是上午")
	default:
		fmt.Println("现在是下午")
	}
	whatAmI := func(i interface{}) {
		switch t := i.(type) {
		case bool:
			fmt.Println("bool")
		case int:
			fmt.Println("int")
		default:
			fmt.Printf("other type %T", t)
		}
	}
	whatAmI(2)
	whatAmI(true)
	whatAmI("hehe")
}
