
-- Environment Variables
local EngineSourceContentDir, GameInstallDir, ExternalDir, SFMLDir

do

	-- GameInstallDir
	do 
		local errorMessage
		GameInstallDir, errorMessage = GetEnvironmentVariable("GameInstallDir")

		if not GameInstallDir then 
			error(errorMessage)
		else
			CreateDirectoryIfItDoesntExist( GameInstallDir )
		end
	end

	-- EngineSourceContentDir
	do
		local errorMessage
		EngineSourceContentDir, errorMessage = GetEnvironmentVariable( "EngineSourceContentDir" )
		if not EngineSourceContentDir then
			error( errorMessage )
		end
	end

	-- External Dir
	do 
		local errorMessage
		ExternalDir, errorMessage = GetEnvironmentVariable("ExternalDir")
		if not ExternalDir then 
			error(errorMessage)
		end
	end
	
	-- Copy SFMLDir .dll file
	do 
		local errorMessage
		SFMLDir, errorMessage = GetEnvironmentVariable("SFMLDir")

		if not SFMLDir then 
			error(errorMessage)
		else
			local Files = GetFilesInDirectory( SFMLDir )

			for i, File in ipairs( Files ) do
				local sourceFileName = File:sub( #SFMLDir + 1 )

				local targetPath = GameInstallDir .. sourceFileName
				
				print( File ) 
				print( targetPath )

				local result, errorMessage = CopyFile(File, targetPath)

				if result then
					print( "Copied " .. sourceFileName )
				else
					OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
				end
			end
		end
	end


	-- Copy Shaders
	do
		local errorMessage

		local builtPath = GameInstallDir .. "Assets\\"
		CreateDirectoryIfItDoesntExist( builtPath )

		local sourceFilePath = EngineSourceContentDir
		local Files = GetFilesInDirectory( sourceFilePath )

		for i, File in ipairs( Files ) do

			if IsDirectory(File) then

				local directoryName = File:sub( #sourceFilePath + 1 )
				local targetPath = builtPath .. directoryName .. '\\'
				CreateDirectoryIfItDoesntExist( targetPath )

			else

				local sourceFileName = File:sub( #sourceFilePath + 1 )
				local targetPath = builtPath .. sourceFileName

				local result, errorMessage = CopyFile(File, targetPath)

				if result then
					print( "Copied " .. sourceFileName )
				else
					OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
				end
			end
		end
	end


end