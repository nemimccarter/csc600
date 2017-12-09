# Nehemya McCarter-Ribakoff #
# Dujomvic                  #
# CSC 600 / MWF 12:10PM     #
# HW4 Prolog                #
# 11 December 2017          #

# 1. Main Iterators
counter = 0
loop do
    counter += 1
    puts "loop: iteration #{counter}"
    if counter == 5
        break
    end
end

counter = 1
while counter <= 5 do
    puts("while: iteration #{counter}")
    counter += 1
end

counter = 1
until counter > 5
    puts("until iteration: #{counter}")
    counter += 1
end

for index in 1..5
    puts "for iteration: #{index}"
end

1.upto(5) { |index| puts "upto iteration: #{index}" }

5.downto(1) { |index| puts "downto: #{index}" }

5.times do |index|
    puts "times iteration: #{index}"
end

puts "\nThe each modifier:\n"
this_assignment = [ "this", "is", "incredibly", "tedious"]
this_assignment.each {|element| print element, " " }

puts "\nThe map modifier on the previous array:\n"
doubled = this_assignment.map do |element|
    element += element
end
puts doubled

puts "\nThe step modifier, counting by 2s on 0..5\n"

range = 0..5
puts "Range: #{range}"
range.step(2) {|x| puts x}
range.step(3) {|x| puts x}

letters = ['i', 'am', 'bored']
letters.collect { |index| puts index + "!"}

puts "\nThe select modifier\n"
[1, 2, 3, 4, 5].select {|num| puts num.even?}

puts "\nThe reject modifier\n"
[1, 2, 3, 4, 5].reject {|num| puts num.even?}

# 2. limited and sorted recognizers
puts "\nThe limited?(amin, amax) recognizer\n"
sorted_array = [656, 657, 658, 659]
unsorted_array = [554, 34, 5, 27]

class Array
    def limited?(amin, amax)
        self.each {
            |index| 
            if (index < amin || index > amax)
                return false
                return
            end
        }
        return true
    end
end

[1, 2, 3, 4].limited?(1, 3)

puts "\nThe sorted? recognizer\n"
class Array
    def sorted?
        if self.each_cons(2).all? { |a, b| a >= b }
            return '-1'
        elsif self.each_cons(2).all? { |a, b| a <= b }
            return '+1'
        else
            return 0
        end
    end
end

puts [7, 8, 9, 10].sorted?

# 4. Class Sphere
# define class Sphere
class Sphere
    def initialize(radius)
        @radius = radius
    end
    def area
        puts 4 * @radius**2 * 3.14159
    end
    def volume
        puts 4 * @radius**3 * (3.14159 / 3)
    end
end

class Ball < Sphere
    def initialize(radius, color)
        super(radius)
        @color = color
    end
end

class MyBall < Ball
    def initialize(radius, color, owner)
        super(radius, color)
        @owner = owner
    end
end


boing = MyBall.new(10, 'blue', 'me')
puts boing.instance_variables
