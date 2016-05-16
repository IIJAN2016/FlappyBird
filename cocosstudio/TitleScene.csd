<GameFile>
  <PropertyGroup Name="TitleScene" Type="Scene" ID="09745aac-c451-44d2-a175-fa052f0efac5" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="288.0000" Y="512.0000" />
        <Children>
          <AbstractNodeData Name="back" ActionTag="999146604" Tag="3" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" ctype="SpriteObjectData">
            <Size X="288.0000" Y="512.0000" />
            <Children>
              <AbstractNodeData Name="character" ActionTag="-1751664700" Tag="6" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="144.0000" RightMargin="144.0000" TopMargin="227.6244" BottomMargin="284.3756" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="144.0000" Y="284.3756" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5554" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Character.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="ground" ActionTag="1929538871" Tag="47" IconVisible="True" RightMargin="288.0000" TopMargin="402.0000" BottomMargin="110.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position Y="110.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.2148" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Ground.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="logo" ActionTag="-512354036" Tag="54" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="55.0000" RightMargin="55.0000" TopMargin="138.0000" BottomMargin="326.0000" ctype="SpriteObjectData">
                <Size X="178.0000" Y="48.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="144.0000" Y="350.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6836" />
                <PreSize X="0.6181" Y="0.0938" />
                <FileData Type="Normal" Path="Assets/logo/logo_flappy_bird.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="playButton" ActionTag="1114656042" Tag="58" IconVisible="False" LeftMargin="22.0000" RightMargin="150.0000" TopMargin="342.0000" BottomMargin="100.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="48" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0000" Y="70.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="80.0000" Y="135.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2778" Y="0.2637" />
                <PreSize X="0.4028" Y="0.1367" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Assets/UI/btn_play.png" Plist="" />
                <NormalFileData Type="Normal" Path="Assets/UI/btn_play.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="rankingButton" ActionTag="-624278694" Tag="60" IconVisible="False" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="151.9968" RightMargin="19.9968" TopMargin="342.0000" BottomMargin="100.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="48" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0064" Y="70.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="210.0000" Y="135.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7292" Y="0.2637" />
                <PreSize X="0.4028" Y="0.1367" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Assets/UI/leaderboard.png" Plist="" />
                <NormalFileData Type="Normal" Path="Assets/UI/leaderboard.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="rateButton" ActionTag="-2086506576" Tag="61" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="107.0000" RightMargin="107.0000" TopMargin="265.6609" BottomMargin="198.3391" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="44" Scale9Height="26" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="74.0000" Y="48.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="144.0000" Y="222.3391" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4343" />
                <PreSize X="0.2569" Y="0.0938" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Assets/UI/btn_rate.png" Plist="" />
                <NormalFileData Type="Normal" Path="Assets/UI/btn_rate.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="144.0000" Y="256.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="Assets/background/back1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="screen_shot_4" Visible="False" ActionTag="-2073151266" VisibleForFrame="False" Alpha="195" Tag="12" IconVisible="False" RightMargin="54.0000" TopMargin="73.7000" BottomMargin="78.3000" ctype="SpriteObjectData">
            <Size X="234.0000" Y="360.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position Y="258.3000" />
            <Scale ScaleX="1.2375" ScaleY="1.2337" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.5045" />
            <PreSize X="0.8125" Y="0.7031" />
            <FileData Type="Normal" Path="screen_shot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>