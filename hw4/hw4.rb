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
