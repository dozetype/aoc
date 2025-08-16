# convert one form of unit to another form, return none if cannot be converted
# example 1m -> m = 100cm, 1m -> deg = none

# Graph type approach
class Node:
    def __init__(self, unit) -> None: 
        # unit will hold nodes unit, edges are for possible conversions
        self.unit = unit
        self.edges = {}
    
    def add_edges(self, possible_unit, operator, operand):
        self.edges[possible_unit] = Edge(possible_unit, operator, operand)
        
    def convert(self, number, to_unit):
        # BFS for indirect conversions
        q = []
        visited = set()
        q.append((number, self.unit))
        
        while q:
            curr_num, curr_unit = q.pop(0)
            if curr_unit == to_unit:
                return curr_num
                
            visited.add(curr_unit)
            if not nodes.get(curr_unit):
                continue
            curr_node = nodes[curr_unit]
            for unit, edge in curr_node.edges.items():
                if(unit not in visited):
                    new_num = eval(f"{curr_num} {edge.operator} {edge.operand}")
                    q.append((new_num, unit))
        return None
        
class Edge:
    def __init__(self, unit, operator, operand) -> None:
        self.unit = unit
        self.operator = operator
        self.operand = operand
        
conversions = [("cm", "m", "*", 0.01), ("m", "cm", "*", 100), ("m", "in", "*", 39.37008), ("deg", "k", "+", 273.15)]
nodes = {}

for conv in conversions:
    from_unit, to_unit, operator, operand = conv
    if not nodes.get(from_unit):
        nodes[from_unit] = Node(from_unit)
    if not nodes[from_unit].edges.get(to_unit):
        nodes[from_unit].add_edges(to_unit, operator, operand)


inputs = [("cm", 50, "in"), ("cm", 123, "m"), ("deg", 10, "k"), ("m", 999, "in"), ("m", 10, "j")]
for input in inputs:
    from_unit, num, to_unit = input
    if nodes.get(from_unit):
        print(f"converting {num}{from_unit} to {to_unit} = {nodes[from_unit].convert(num, to_unit)}{to_unit}")
