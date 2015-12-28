g_stringError=stringstream ""
g_string=stringstream ""
g_Path= "I:/Trab/ZShoot/Distribution/Data/Scripts/"
global totalMaterial = 0
function DumpDummies  =
(
	try
	(

		for obj in $* do
		(
			
			if (classOf obj) ==Dummy then
			(
				print obj
				format "%\n" (getUserPropBuffer obj)to:g_string
			)
		)
	)
	catch
	(
		format "*** % ***\n" (getCurrentException()) to:g_stringError
		messageBox (g_stringError as string ) 
	)
)
function DummiesToLua =
(
	
	filename = g_Path+"dummies.lua"
	out_file = createfile filename
	------ save string to file ----
	DumpDummies() 
	g_stringstring = (g_string as string ) 
	
	---- clean string ---
	r = g_stringstring.count
	for i = 1 to r do
	(
		if g_stringstring[i] == "\\" then
		(
			g_stringstring = replace g_stringstring i 1 "/"
		)
	)
	format "%" g_stringstring to:out_file
	format "%" g_stringstring 
	close out_file
)

global totalMaterial = 0
function DumpSplines  =
(
	try
	(

		for obj in $* do
		(
			
			if (classOf obj) ==line then
			(
				print obj
				format "X.PathFactory:beginCreateFollowSplineAnimator();\n" to:g_string
				format "X.PathFactory:setName(\"%\");\n" obj.name to:g_string
				--getKnotPoint $Line01 1 1 	
				for k = 1 to (numKnots obj) do
				(
					knt = getKnotPoint  obj 1 k 
					format "X.PathFactory:addPoint (%, %, %) \n" -knt.y knt.z knt.x to:g_string
				)
				format "X.PathFactory:endCreateFollowSplineAnimator();\n" to:g_string
			)
		)
	)
	catch
	(
		format "*** % ***\n" (getCurrentException()) to:g_stringError
		messageBox (g_stringError as string ) 
	)
)
function SplinesToLua =
(
	

	--out_file = createfile "c:/level2.lua"
	filename = g_Path+"level2.lua"
	out_file = createfile filename
	------ save string to file ----
	DumpSplines() 
	g_stringstring = (g_string as string ) 
	
	---- clean string ---
	r = g_stringstring.count
	for i = 1 to r do
	(
		if g_stringstring[i] == "\\" then
		(
			g_stringstring = replace g_stringstring i 1 "/"
		)
	)
	format "%" g_stringstring to:out_file
	format "%" g_stringstring 
	close out_file
)
function AllToLua =
(
	

	--out_file = createfile "c:/level2.lua"
	filename = g_Path+"level2.lua"
	out_file = createfile filename
	------ save string to file ----
	format "require \"Data/Scripts/factory\"\n" to:g_string
	DumpDummies() 
	DumpSplines() 

	g_stringstring = (g_string as string ) 
	
	---- clean string ---
	r = g_stringstring.count
	for i = 1 to r do
	(
		if g_stringstring[i] == "\\" then
		(
			g_stringstring = replace g_stringstring i 1 "/"
		)
	)
	format "%" g_stringstring to:out_file
	format "%" g_stringstring 
	close out_file
)
AllToLua()
