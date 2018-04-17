//************************************ bs::framework - Copyright 2018 Marko Pintera **************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#pragma once

#include "BsPrerequisites.h"
#include "GUI/BsGUISkin.h"
#include "Utility/BsModule.h"
#include "Math/BsVector2I.h"
#include "BsApplication.h"

namespace bs
{
	/** @addtogroup Resources-Engine
	 *  @{
	 */

	/**	Types of builtin meshes that are always available. */
	enum class BuiltinMesh
	{
		Box, Sphere, Cone, Quad, Disc
	};

	/**	Types of builtin textures that are always available. */
	enum class BuiltinTexture
	{
		White, Black, Normal
	};

	/** Types of builtin shaders that are always available. */
	enum class BuiltinShader
	{
		Custom, 
		/** Physically based shader used for opaque 3D geometry. */
		Standard, 
		/** Physically based shader used for transparent 3D geometry. */
		Transparent
	};

	/**	Holds references to built-in resources used by the core engine. */
	class BS_EXPORT BuiltinResources : public bs::Module<BuiltinResources>
	{
	public:
		BuiltinResources();
		~BuiltinResources();

		/**	Returns the default skin used by engine GUI elements. */
		const HGUISkin& getGUISkin() const { return mSkin; }

		/**	Returns an empty skin used to be used when no other is available. */
		const HGUISkin& getEmptyGUISkin() const { return mEmptySkin; }

		/**	Returns a small entirely white texture. */
		const HSpriteTexture& getWhiteSpriteTexture() const { return mWhiteSpriteTexture; }

		/**	Returns a 2x2 sprite texture that can be used when no other is available. */
		const HSpriteTexture& getDummySpriteTexture() const { return mDummySpriteTexture; }

		/**	Returns a dummy 2x2 texture that may be used when no other is available. Don't modify the returned texture. */
		const HTexture& getDummyTexture() const { return mDummyTexture; }

		/**	Returns image data for an arrow cursor, along with its hotspot. */
		const PixelData& getCursorArrow(Vector2I& hotSpot);

		/**	Returns image data for an arrow with dragged object cursor, along with its hotspot. */
		const PixelData& getCursorArrowDrag(Vector2I& hotSpot);
		
		/**	Returns image data for a wait cursor, along with its hotspot. */
		const PixelData& getCursorWait(Vector2I& hotSpot);
		
		/**	Returns image data for an "I" beam cursor, along with its hotspot. */
		const PixelData& getCursorIBeam(Vector2I& hotSpot);
		
		/**	Returns image data for a NESW resize cursor, along with its hotspot. */
		const PixelData& getCursorSizeNESW(Vector2I& hotSpot);
		
		/**	Returns image data for a NS resize cursor, along with its hotspot. */
		const PixelData& getCursorSizeNS(Vector2I& hotSpot);
		
		/**	Returns image data for a NWSE resize cursor, along with its hotspot. */
		const PixelData& getCursorSizeNWSE(Vector2I& hotSpot);
		
		/**	Returns image data for a WE resize cursor, along with its hotspot. */
		const PixelData& getCursorSizeWE(Vector2I& hotSpot);
		
		/**	Returns image data for a deny cursor, along with its hotspot. */
		const PixelData& getCursorDeny(Vector2I& hotSpot);
		
		/**	Returns image data for a move left-right cursor, along with its hotspot. */
		const PixelData& getCursorMoveLeftRight(Vector2I& hotSpot);

		/**	Returns the default application icon. */
		const PixelData& getBansheeIcon();

		/**	Returns one of the builtin shader types. */
		HShader getBuiltinShader(BuiltinShader type) const;

		/**	Creates a material used for textual sprite rendering (for example text in GUI). */
		HMaterial createSpriteTextMaterial() const;

		/**	Creates a material used for image sprite rendering (for example images in GUI). */
		HMaterial createSpriteImageMaterial() const;

		/**	Creates a material used for non-transparent image sprite rendering (for example images in GUI). */
		HMaterial createSpriteNonAlphaImageMaterial() const;

		/** Creates a material used for antialiased line rendering (for example curve rendering in GUI). */
		HMaterial createSpriteLineMaterial() const;

		/**	Retrieves one of the builtin meshes. */
		HMesh getMesh(BuiltinMesh mesh) const;

		/**
		 * Loads a shader at the specified path.
		 * 
		 * @param[in]	path	Path relative to the default shader folder with no file extension.
		 */
		HShader getShader(const Path& path);

		/** Returns the default font used by the engine. */
		HFont getDefaultFont() const { return mFont; }

		/**	Retrieves one of the builtin textures. */
		static HTexture getTexture(BuiltinTexture type);

		/**	Returns absolute path to the builtin shader folder where raw shader files are located. */
		static Path getRawShaderFolder();

		/**	Returns absolute path to the builtin shader include folder. */
		static Path getShaderIncludeFolder();

		/**	Returns absolute path to the builtin icons folder. */
		static Path getIconFolder();

		static const String IconTextureName;
		static const String MultiLineLabelStyle;

	private:
		/**
		 * Imports all necessary resources and converts them to engine-ready format.
		 *
		 * @note	
		 * Normally you only want to use this during development phase and then ship with engine-ready format only.
		 */
		void preprocess(bool forceImport, time_t lastUpdateTime);

		/**	Generates the default engine skin and all GUI element styles. */
		SPtr<GUISkin> generateGUISkin();

		/**	Generates the builtin meshes. */
		void generateMeshes();

		/**	Generates the builtin textures. */
		void generateTextures();

		/**	Loads a GUI skin texture with the specified filename. */
		HSpriteTexture getSkinTexture(const String& name);

		/**	Loads a cursor texture with the specified filename. */
		HTexture getCursorTexture(const String& name);

		HGUISkin mEmptySkin;
		HGUISkin mSkin;
		HFont mFont;

		SPtr<PixelData> mCursorArrow;
		SPtr<PixelData> mCursorArrowDrag;
		SPtr<PixelData> mCursorArrowLeftRight;
		SPtr<PixelData> mCursorIBeam;
		SPtr<PixelData> mCursorDeny;
		SPtr<PixelData> mCursorWait;
		SPtr<PixelData> mCursorSizeNESW;
		SPtr<PixelData> mCursorSizeNS;
		SPtr<PixelData> mCursorSizeNWSE;
		SPtr<PixelData> mCursorSizeWE;
		SPtr<PixelData> mBansheeIcon;

		HSpriteTexture mWhiteSpriteTexture;
		HSpriteTexture mDummySpriteTexture;

		HTexture mDummyTexture;

		HShader mShaderSpriteText;
		HShader mShaderSpriteImage;
		HShader mShaderSpriteNonAlphaImage;
		HShader mShaderSpriteLine;
		HShader mShaderDiffuse;
		HShader mShaderTransparent;

		SPtr<ResourceManifest> mResourceManifest;

		Path mBuiltinRawDataFolder;
		Path mBuiltinDataFolder;
		Path mEngineSkinSpritesFolder;
		Path mEngineShaderFolder;
		Path mEngineMeshFolder;
		Path mEngineCursorFolder;

		Path ResourceManifestPath;

		static constexpr const char* SHADER_FOLDER = "Shaders/";
		static constexpr const char* CURSOR_FOLDER = "Cursors/";
		static constexpr const char* ICON_FOLDER = "Icons/";
		static constexpr const char* SKIN_FOLDER = "Skin/"; 
		static constexpr const char* SHADER_INCLUDE_FOLDER = "Shaders/Includes/";
		static constexpr const char* MESH_FOLDER = "Meshes/";
		static constexpr const char* TEXTURE_FOLDER = "Textures/";
		static constexpr const char* SPRITE_FOLDER = "Sprites/";

		static const char* DataListFile;

		static const String DefaultFontFilename;
		static const UINT32 DefaultFontSize;

		static const Color TextNormalColor;
		static const Color TextActiveColor;

		static const String GUISkinFile;
		static const String WhiteTex;

		static const String ButtonNormalTex;
		static const String ButtonHoverTex;
		static const String ButtonActiveTex;

		static const String ToggleNormalTex;
		static const String ToggleHoverTex;
		static const String ToggleNormalOnTex;
		static const String ToggleHoverOnTex;

		static const String InputBoxNormalTex;
		static const String InputBoxHoverTex;
		static const String InputBoxFocusedTex;

		static const String ScrollBarUpNormalTex;
		static const String ScrollBarUpHoverTex;
		static const String ScrollBarUpActiveTex;

		static const String ScrollBarDownNormalTex;
		static const String ScrollBarDownHoverTex;
		static const String ScrollBarDownActiveTex;

		static const String ScrollBarLeftNormalTex;
		static const String ScrollBarLeftHoverTex;
		static const String ScrollBarLeftActiveTex;

		static const String ScrollBarRightNormalTex;
		static const String ScrollBarRightHoverTex;
		static const String ScrollBarRightActiveTex;

		static const String ScrollBarHandleHorzNormalTex;
		static const String ScrollBarHandleHorzHoverTex;
		static const String ScrollBarHandleHorzActiveTex;

		static const String ScrollBarHandleVertNormalTex;
		static const String ScrollBarHandleVertHoverTex;
		static const String ScrollBarHandleVertActiveTex;

		static const String ScrollBarResizeableHandleHorzNormalTex;
		static const String ScrollBarResizeableHandleHorzHoverTex;
		static const String ScrollBarResizeableHandleHorzActiveTex;

		static const String ScrollBarResizeableHandleVertNormalTex;
		static const String ScrollBarResizeableHandleVertHoverTex;
		static const String ScrollBarResizeableHandleVertActiveTex;

		static const String ScrollBarHBgTex;
		static const String ScrollBarVBgTex;

		static const String SliderHBackgroundTex;
		static const String SliderHFillTex;
		static const String SliderVBackgroundTex;
		static const String SliderVFillTex;
		static const String SliderHandleNormalTex;
		static const String SliderHandleHoverTex;
		static const String SliderHandleActiveTex;

		static const String DropDownBtnNormalTex;
		static const String DropDownBtnHoverTex;
		static const String DropDownBtnActiveTex;

		static const String DropDownBoxBgTex;
		static const String DropDownBoxSideBgTex;
		static const String DropDownBoxHandleTex;

		static const String DropDownBoxEntryNormalTex;
		static const String DropDownBoxEntryHoverTex;

		static const String DropDownBoxBtnUpNormalTex;
		static const String DropDownBoxBtnUpHoverTex;

		static const String DropDownBoxBtnDownNormalTex;
		static const String DropDownBoxBtnDownHoverTex;

		static const String DropDownBoxEntryExpNormalTex;
		static const String DropDownBoxEntryExpHoverTex;

		static const String DropDownBoxEntryToggleNormalTex;
		static const String DropDownBoxEntryToggleHoverTex;
		static const String DropDownBoxEntryToggleNormalOnTex;
		static const String DropDownBoxEntryToggleHoverOnTex;

		static const String DropDownSeparatorTex;

		static const String CursorArrowTex;
		static const String CursorArrowDragTex;
		static const String CursorArrowLeftRightTex;
		static const String CursorIBeamTex;
		static const String CursorDenyTex;
		static const String CursorWaitTex;
		static const String CursorSizeNESWTex;
		static const String CursorSizeNSTex;
		static const String CursorSizeNWSETex;
		static const String CursorSizeWETex;

		static const Vector2I CursorArrowHotspot;
		static const Vector2I CursorArrowDragHotspot;
		static const Vector2I CursorArrowLeftRightHotspot;
		static const Vector2I CursorIBeamHotspot;
		static const Vector2I CursorDenyHotspot;
		static const Vector2I CursorWaitHotspot;
		static const Vector2I CursorSizeNESWHotspot;
		static const Vector2I CursorSizeNSHotspot;
		static const Vector2I CursorSizeNWSEHotspot;
		static const Vector2I CursorSizeWEHotspot;

		static const String ShaderSpriteTextFile;
		static const String ShaderSpriteImageAlphaFile;
		static const String ShaderSpriteImageNoAlphaFile;
		static const String ShaderSpriteLineFile;
		static const String ShaderDiffuseFile;
		static const String ShaderTransparentFile;

		static const String MeshSphereFile;
		static const String MeshBoxFile;
		static const String MeshConeFile;
		static const String MeshQuadFile;
		static const String MeshDiscFile;

		static const String TextureWhiteFile;
		static const String TextureBlackFile;
		static const String TextureNormalFile;
	};

	/**	Provides easy access to BuiltinResources. */
	BS_EXPORT BuiltinResources& gBuiltinResources();

	/** @} */
}
