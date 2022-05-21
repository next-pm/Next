## Specs of valiables
lower Camel Case

```python
# Example
intToString = int_to_string(987)
randomNumbre = random()
```

## Specs of functions
lower Snake Case

```python
# Example
def int_to_string(num: int) -> str:
```

Whenever possible, the type of the arguments received by the function and the return type must be specified, to help in error management.

## Specs of class
Upper init Snake Case
```python
# Example
class Person_of_school_t:
    .
    .
    .
```

If it is a class that wants to express an object, add '_t' to the end of the class name

## Specs of packages
*Name of file:* Lower Snake Case  
*Name of package in code:* Upper Snake Case
```python
# Example
# src/models/person_of_school.py
class Person_of_school_t:
    .
    .
    .

# main.py
# With import a class
from src.models.person_of_school import Person_of_school_t as Person_of_school_t

# Can also be used
from src.models.person_of_school import Person_of_school_t

# but never use
import src.models.person_of_school
```