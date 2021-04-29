package main

import "fmt"

type point struct {
	x int
	y int
}

func main() {
	p := point{
		x: 10,
		y: 10,
	}
	//值
	fmt.Printf("%v \n", p)
	//+结构体的字段名
	fmt.Printf("%+v \n", p)
	//根据 Go 语法输出值，即会产生该值的源码片段
	fmt.Printf("%#v \n", p)
	//类型
	fmt.Printf("%T \n", p)
	//布尔类型
	fmt.Printf("%t \n", false)

	fmt.Printf("%d \n", p.x)
	fmt.Printf("%b \n", p.x)
	//字符
	fmt.Printf("%c \n", 33)
	//16进制
	fmt.Printf("%x \n", p)
	//小数
	fmt.Printf("%f \n", 123400000.0)
	//科学计数法
	fmt.Printf("%e\n", 123400000.0)
	fmt.Printf("%E\n", 123400000.0)
	fmt.Printf("%s\n", "字符串")
	//带引号输出
	fmt.Printf("%q\n", "字符串")
	fmt.Printf("%x\n", "hex this")
	fmt.Printf("%p\n", &p)
	fmt.Printf("|%6d|%6d|\n", 123, 23)
	fmt.Printf("|%6.2f|%6.2f|\n", 23.22, 22.22)
	fmt.Printf("|%-6.2f|%-6.2f|\n", 123.22, 22.22)
	fmt.Printf("|%6.2f|%6.2f|\n", 123.22, 22.22)

}
