IF(GLEW_FOUND AND BOOST_FILESYSTEM_FOUND)

  ADD_LIBRARY(OpenEngine_Resources
	      File.cpp
	      DirectoryManager.cpp
              OBJResource.cpp
	      TGAResource.cpp
	      )

  TARGET_LINK_LIBRARIES(OpenEngine_Resources
			OpenEngine_Utils
			${GLEW_LIBRARIES}
			${GLUT_LIBRARY}
			${BOOST_FILESYSTEM_LIB})

ENDIF(GLEW_FOUND AND BOOST_FILESYSTEM_FOUND)
