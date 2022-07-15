#Penis 
import turtle

t = turtle.Turtle()

t.setx(0)
t.sety(-100)
t.circle(100,90)
t.sety(0)
t.setx(100)
t.setx(-100)
t.circle(-100,-90)
t.penup()
t.goto(100,0)
t.pendown()
t.goto(100,250)
t.circle(-100)
t.goto(-100,250)
t.circle(-100)
t.goto(-100,0)
turtle.done()
