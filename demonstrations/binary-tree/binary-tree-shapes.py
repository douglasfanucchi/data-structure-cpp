# This script is to generate images and animations for binary tree demonstrations.
# If you want to run this, you should have manim installed.
# https://docs.manim.community/

from manim import *

class WorstBinaryTreeShape(Scene):
    def construct(self):
        vertices = [1, 2, 3, 4, 5]
        edges = [(1, 2), (2, 3), (3, 4), (4, 5)]
        graph = Graph(vertices,
                      edges,
                      vertex_config={
                        'radius': 0.30,
                        'fill_color': ManimColor("#808080")
                      },
                      edge_config={'stroke_color': ManimColor("#808080")},
                      layout_scale=2,
                      layout="tree",
                      root_vertex=1,
                    )
        graph.scale(1.5)
        self.add(graph)

class BestBinaryTreeShape(Scene):
  def construct(self):
    vertices = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    edges = [(1, 2), (2, 3), (2, 4), (3, 5), (3, 6), (4, 7), (4, 8), (1, 9), (9, 10), (9, 11), (10, 12), (10, 13), (11, 14), (11, 15)]
    graph = Graph(
      vertices,
      layout='tree',
      edges=edges,
      root_vertex=1,
      vertex_config={
        'radius': 0.3,
        'fill_color': ManimColor("#808080")
      },
      edge_config={
        'stroke_color': ManimColor("#808080")
      },
      layout_scale=6.5,
    )
    self.add(graph)