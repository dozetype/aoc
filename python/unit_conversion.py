# convert one form of unit to another form, return none if cannot be converted
# example 1m -> m = 100cm, 1m -> deg = none

# Graph type approach
class node:
    def __init__(self, unit) -> None: 
        # unit will hold nodes unit, edges are for possible conversions
        self.unit = unit
        self.edges = {}
    
    def add_edges(self, possible_unit, operator, operand):
        self.edges[possible_unit] = edge(possible_unit, operator, operand)
        
    def eval(self, number, to_unit):
        if self.edges[to_unit]:
            edge = self.edges[to_unit]
            return eval(f"{number} {edge.operator} {edge.operand}")
        
class edge:
    def __init__(self, unit, operator, operand) -> None:
        self.unit = unit
        self.operator = operator
        self.operand = operand
        
conversions = [("cm", "m", "*", 0.01), ("m", "cm", "*", 100), ("m", "in", "*", 39.37008), ("deg", "k", "+", 273.15)]
nodes = {}

for conv in conversions:
    from_unit, to_unit, operator, operand = conv
    if not nodes.get(from_unit):
        nodes[from_unit] = node(from_unit)
    if not nodes[from_unit].edges.get(to_unit):
        nodes[from_unit].add_edges(to_unit, operator, operand)


inputs = [("cm", 123, "m"), ("deg", 10, "k"), ("m", 999, "in")]

for input in inputs:
    from_unit, num, to_unit = input
    print(f"converting {num}{from_unit} to {to_unit} = {nodes[from_unit].eval(num, to_unit)}{to_unit}")
