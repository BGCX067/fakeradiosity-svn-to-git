require "Data/Scripts/factory"
CREATE_WAVE

{

name = "wave1",

path = "Line01",

number=6,

shield=1,

mesh="ship.3ds",

}


CREATE_WAVE

{

name = "wave4",

path = "Line04",

number=6,

shield=1,

mesh="ship.3ds",
collisionradius = 1.0,
}


CREATE_WAVE

{

name = "wave3",

path = "Line03",

number=6,

shield=1,

mesh="ship.3ds",
collisionradius = 1.0,

}


CREATE_WAVE

{

name = "wave2",

path = "Line02",

number=6,

shield=1,

mesh="ship.3ds",
collisionradius = 1.0,

}


X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line01");
X.PathFactory:addPoint (66.1239, 115.316, -2.69514) 
X.PathFactory:addPoint (58.2103, 79.9382, 0.189041) 
X.PathFactory:addPoint (56.1104, 64.1497, 0.199448) 
X.PathFactory:addPoint (55.2004, 49.3782, 0.612915) 
X.PathFactory:addPoint (44.8251, 41.3995, 1.89658) 
X.PathFactory:addPoint (28.7634, 41.8281, 1.50902) 
X.PathFactory:addPoint (15.2519, 37.9444, 4.21828) 
X.PathFactory:addPoint (5.17088, 34.0605, 3.89079) 
X.PathFactory:addPoint (-4.02557, 25.7525, 4.48799) 
X.PathFactory:addPoint (-22.5353, 14.8521, 7.68082) 
X.PathFactory:addPoint (-79.0028, -13.823, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line02");
X.PathFactory:addPoint (105.628, 170.439, -2.69514) 
X.PathFactory:addPoint (103.48, 82.5605, 0.189041) 
X.PathFactory:addPoint (102.796, 59.4932, 0.199448) 
X.PathFactory:addPoint (99.1195, 49.1916, 0.612915) 
X.PathFactory:addPoint (84.9402, 46.3729, 1.89658) 
X.PathFactory:addPoint (75.6164, 41.3529, 1.50902) 
X.PathFactory:addPoint (77.5628, 28.8618, 4.21828) 
X.PathFactory:addPoint (76.9972, 11.0606, 3.89079) 
X.PathFactory:addPoint (79.8758, -7.92145, 4.48799) 
X.PathFactory:addPoint (73.0742, -23.2305, 7.68082) 
X.PathFactory:addPoint (20.0204, -54.9231, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line03");
X.PathFactory:addPoint (226.818, 31.9587, -2.69514) 
X.PathFactory:addPoint (224.403, 18.8172, 0.189041) 
X.PathFactory:addPoint (212.547, 14.3867, 0.199448) 
X.PathFactory:addPoint (204.469, 28.5385, 0.612915) 
X.PathFactory:addPoint (213.358, 39.4529, 1.89658) 
X.PathFactory:addPoint (222.003, 27.1043, 1.50902) 
X.PathFactory:addPoint (213.23, 15.8062, 4.21828) 
X.PathFactory:addPoint (200.065, 16.961, 3.89079) 
X.PathFactory:addPoint (185.711, 23.2366, 4.48799) 
X.PathFactory:addPoint (170.673, 18.5106, 7.68082) 
X.PathFactory:addPoint (97.7139, -16.9562, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line04");
X.PathFactory:addPoint (205.253, 146.682, -2.69514) 
X.PathFactory:addPoint (205.987, 91.276, 0.189041) 
X.PathFactory:addPoint (196.041, 49.5255, 0.199448) 
X.PathFactory:addPoint (175.318, 47.4047, 0.612915) 
X.PathFactory:addPoint (159.022, 45.6854, 1.89658) 
X.PathFactory:addPoint (138.295, 45.1061, 1.50902) 
X.PathFactory:addPoint (111.504, 46.091, 4.21828) 
X.PathFactory:addPoint (87.676, 45.0727, 3.89079) 
X.PathFactory:addPoint (58.6305, 43.1138, 4.48799) 
X.PathFactory:addPoint (27.9801, 42.6445, 7.68082) 
X.PathFactory:addPoint (-154.39, 43.2393, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line05");
X.PathFactory:addPoint (64.0027, -11.9474, -2.69514) 
X.PathFactory:addPoint (61.5873, -25.0889, 0.189041) 
X.PathFactory:addPoint (56.3925, -21.5675, 0.199448) 
X.PathFactory:addPoint (41.7763, -10.0032, 0.612915) 
X.PathFactory:addPoint (46.3745, 9.02174, 1.89658) 
X.PathFactory:addPoint (39.9815, 24.8181, 1.50902) 
X.PathFactory:addPoint (27.1328, 27.4054, 14.168) 
X.PathFactory:addPoint (6.51545, 21.9553, 3.89079) 
X.PathFactory:addPoint (-9.71424, 18.5037, 4.48799) 
X.PathFactory:addPoint (-31.9894, 41.6723, 7.68082) 
X.PathFactory:addPoint (-66.1344, 75.6588, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
X.PathFactory:beginCreateFollowSplineAnimator();
X.PathFactory:setName("Line06");
X.PathFactory:addPoint (299.925, 81.7774, -2.69514) 
X.PathFactory:addPoint (297.51, 68.6359, 0.189041) 
X.PathFactory:addPoint (285.654, 64.2054, 0.199448) 
X.PathFactory:addPoint (277.576, 78.3572, 0.612915) 
X.PathFactory:addPoint (286.465, 89.2716, 1.89658) 
X.PathFactory:addPoint (295.11, 76.923, 1.50902) 
X.PathFactory:addPoint (286.337, 65.6249, 4.21828) 
X.PathFactory:addPoint (273.172, 66.7797, 3.89079) 
X.PathFactory:addPoint (258.818, 73.0553, 4.48799) 
X.PathFactory:addPoint (243.779, 68.3293, 7.68082) 
X.PathFactory:addPoint (170.821, 32.8625, 8.33994) 
X.PathFactory:endCreateFollowSplineAnimator();
