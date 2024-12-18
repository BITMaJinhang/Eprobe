classdef EprobeUART < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                 matlab.ui.Figure
        TabGroup                 matlab.ui.container.TabGroup
        Tab1                     matlab.ui.container.Tab
        UIAxes_1                 matlab.ui.control.UIAxes
        StopCHN1Button           matlab.ui.control.Button
        StartCHN1Button          matlab.ui.control.Button
        ContinueCHN1Button       matlab.ui.control.Button
        PauseCHN1Button          matlab.ui.control.Button
        ListBox_CH1              matlab.ui.control.ListBox
        CH1Save                  matlab.ui.control.Button
        CHN2Tab                  matlab.ui.container.Tab
        UIAxes_2                 matlab.ui.control.UIAxes
        StopCHN2Button           matlab.ui.control.Button
        StartCHN2Button          matlab.ui.control.Button
        ContinueCHN2Button       matlab.ui.control.Button
        PauseCHN2Button          matlab.ui.control.Button
        ListBox_CH2              matlab.ui.control.ListBox
        CH2Save                  matlab.ui.control.Button
        CHN3Tab                  matlab.ui.container.Tab
        UIAxes_3                 matlab.ui.control.UIAxes
        StopCHN3Button           matlab.ui.control.Button
        StartCHN3Button          matlab.ui.control.Button
        ContinueCHN3Button       matlab.ui.control.Button
        PauseCHN3Button          matlab.ui.control.Button
        ListBox_CH3              matlab.ui.control.ListBox
        CH3Save                  matlab.ui.control.Button
        CHN4Tab                  matlab.ui.container.Tab
        UIAxes_4                 matlab.ui.control.UIAxes
        StopCHN4Button           matlab.ui.control.Button
        StartCHN4Button          matlab.ui.control.Button
        ContinueCHN4Button       matlab.ui.control.Button
        PauseCHN4Button          matlab.ui.control.Button
        ListBox_CH4              matlab.ui.control.ListBox
        CH4Save                  matlab.ui.control.Button
        CHN5Tab                  matlab.ui.container.Tab
        UIAxes_5                 matlab.ui.control.UIAxes
        StopCHN5Button           matlab.ui.control.Button
        StartCHN5Button          matlab.ui.control.Button
        ContinueCHN5Button       matlab.ui.control.Button
        PauseCHN5Button          matlab.ui.control.Button
        ListBox_CH5              matlab.ui.control.ListBox
        CH5Save                  matlab.ui.control.Button
        CHN6Tab                  matlab.ui.container.Tab
        UIAxes_6                 matlab.ui.control.UIAxes
        StopCHN6Button           matlab.ui.control.Button
        StartCHN6Button          matlab.ui.control.Button
        ContinueCHN6Button       matlab.ui.control.Button
        PauseCHN6Button          matlab.ui.control.Button
        ListBox_CH6              matlab.ui.control.ListBox
        CH6Save                  matlab.ui.control.Button
        Panel_2                  matlab.ui.container.Panel
        CHNDropDownLabel         matlab.ui.control.Label
        CHNDropDown              matlab.ui.control.DropDown
        MODEDropDownLabel        matlab.ui.control.Label
        MODEDropDown             matlab.ui.control.DropDown
        param1EditFieldLabel     matlab.ui.control.Label
        param1EditField          matlab.ui.control.NumericEditField
        param2EditFieldLabel     matlab.ui.control.Label
        param2EditField          matlab.ui.control.NumericEditField
        param3EditFieldLabel     matlab.ui.control.Label
        param3EditField          matlab.ui.control.NumericEditField
        param4EditFieldLabel     matlab.ui.control.Label
        param4EditField          matlab.ui.control.NumericEditField
        SENSDropDownLabel        matlab.ui.control.Label
        SENSDropDown             matlab.ui.control.DropDown
        ParamSetButton           matlab.ui.control.Button
        StartAllButton           matlab.ui.control.Button
        StopAllButton            matlab.ui.control.Button
        ConnectButton            matlab.ui.control.Button
        serialDropDown           matlab.ui.control.DropDown
        SearchButton             matlab.ui.control.Button
        ConnectLamp              matlab.ui.control.Lamp
        DEBUGSwitchLabel         matlab.ui.control.Label
        DEBUGSwitch              matlab.ui.control.Switch
        ParametersLabel          matlab.ui.control.Label
        Button                   matlab.ui.control.StateButton
        param5EditFieldLabel     matlab.ui.control.Label
        param5EditField          matlab.ui.control.NumericEditField
        param6EditFieldLabel     matlab.ui.control.Label
        param6EditField          matlab.ui.control.NumericEditField
        param7EditFieldLabel     matlab.ui.control.Label
        param7EditField          matlab.ui.control.NumericEditField
        param8EditFieldLabel     matlab.ui.control.Label
        param8EditField          matlab.ui.control.NumericEditField
        param9EditFieldLabel     matlab.ui.control.Label
        param9EditField          matlab.ui.control.NumericEditField
        param10EditFieldLabel    matlab.ui.control.Label
        param10EditField         matlab.ui.control.NumericEditField
        param11EditFieldLabel    matlab.ui.control.Label
        param11EditField         matlab.ui.control.NumericEditField
        param12EditFieldLabel    matlab.ui.control.Label
        param12EditField         matlab.ui.control.NumericEditField
        param13EditFieldLabel    matlab.ui.control.Label
        param13EditField         matlab.ui.control.NumericEditField
        param14EditFieldLabel    matlab.ui.control.Label
        param14EditField         matlab.ui.control.NumericEditField
        param15EditFieldLabel    matlab.ui.control.Label
        param15EditField         matlab.ui.control.NumericEditField
        param16EditFieldLabel    matlab.ui.control.Label
        param16EditField         matlab.ui.control.NumericEditField
        param17EditFieldLabel    matlab.ui.control.Label
        param17EditField         matlab.ui.control.NumericEditField
        param18EditFieldLabel    matlab.ui.control.Label
        param18EditField         matlab.ui.control.NumericEditField
        param19EditFieldLabel    matlab.ui.control.Label
        param19EditField         matlab.ui.control.NumericEditField
        param20EditFieldLabel    matlab.ui.control.Label
        param20EditField         matlab.ui.control.NumericEditField
        param21EditFieldLabel    matlab.ui.control.Label
        param21EditField         matlab.ui.control.NumericEditField
        param22EditFieldLabel    matlab.ui.control.Label
        param22EditField         matlab.ui.control.NumericEditField
        param23EditFieldLabel    matlab.ui.control.Label
        param23EditField         matlab.ui.control.NumericEditField
        param24EditFieldLabel    matlab.ui.control.Label
        param24EditField         matlab.ui.control.NumericEditField
        param25EditFieldLabel    matlab.ui.control.Label
        param25EditField         matlab.ui.control.NumericEditField
        param26EditFieldLabel    matlab.ui.control.Label
        param26EditField         matlab.ui.control.NumericEditField
        param27EditFieldLabel    matlab.ui.control.Label
        param27EditField         matlab.ui.control.NumericEditField
        param28EditFieldLabel    matlab.ui.control.Label
        param28EditField         matlab.ui.control.NumericEditField
        Panel1                   matlab.ui.container.Panel
        InputdataListBoxLabel    matlab.ui.control.Label
        InputdataListBox         matlab.ui.control.ListBox
        ClearButton              matlab.ui.control.Button
        SaveButton               matlab.ui.control.Button
        ReceiveHEXSwitchLabel    matlab.ui.control.Label
        ReceiveHEXSwitch         matlab.ui.control.Switch
        SendButton               matlab.ui.control.Button
        OutputdataTextArea       matlab.ui.control.TextArea
        ClearTransButton         matlab.ui.control.Button
        SendHEXSwitchLabel       matlab.ui.control.Label
        SendHEXSwitch            matlab.ui.control.Switch
        ClearPlotButton          matlab.ui.control.Button
        OutputdataTextAreaLabel  matlab.ui.control.Label
    end

properties (Access = private)
    serialObj 
    isConnected = false; 
    plotTimer         
    UIupdateTimer        
    CHN_Value = 0
    MODE_Value = 255
    SENS_Value = 0
    MAX_ITEMS = 1000000;  
    isPolting = 1 
    data_x_buffer1 = zeros(0, 0)
    data_y_buffer1 = zeros(0, 0)
    data_x_buffer2 = zeros(0, 0)
    data_y_buffer2 = zeros(0, 0)
    data_x_buffer3 = zeros(0, 0)
    data_y_buffer3 = zeros(0, 0)
    data_x_buffer4 = zeros(0, 0)
    data_y_buffer4 = zeros(0, 0)
    data_x_buffer5 = zeros(0, 0)
    data_y_buffer5 = zeros(0, 0)
    data_x_buffer6 = zeros(0, 0)
    data_y_buffer6 = zeros(0, 0)
    plot_counter = 0
end
    
    methods (Access = public)
function parseSerialData(app, inputData)
    
    packetSize = 4 + 4 + 4; % chn + data_x + data_y, each 4 bytes
    numPackets = floor(length(inputData) / packetSize);
    
    for i = 0:numPackets-1
        startIdx = i * packetSize + 1;
        endIdx = startIdx + packetSize - 1;
        
        packet = inputData(startIdx:endIdx);
        
        chn = typecast(swapbytes(uint8(packet(1:4))), 'single'); 
        data_x = typecast(swapbytes(uint8(packet(5:8))), 'single'); 
        data_y = typecast(swapbytes(uint8(packet(9:12))), 'single');
        pairs = sprintf('%.3f, %.8f', data_x, data_y);

        switch chn
            case 0
                app.data_x_buffer1 = app.data_x_buffer1;
                if numel(app.data_x_buffer1) == 1 && (app.data_x_buffer1(1) == 0 || strcmp(app.data_x_buffer1(1), ""))
                    app.data_x_buffer1(1) = data_x;
                    app.data_y_buffer1(1) = data_x;
                else
                    app.data_x_buffer1 = [app.data_x_buffer1, data_x];
                    app.data_y_buffer1 = [app.data_y_buffer1, data_y];
                end
                current_items = app.ListBox_CH1.Items;
                current_items{1} = pairs; 
                app.ListBox_CH1.Items = current_items;

            case 1
                app.data_x_buffer2 = [app.data_x_buffer2, data_x];
                app.data_y_buffer2 = [app.data_y_buffer2, data_y];
                current_items = app.ListBox_CH2.Items;
                current_items{1} = pairs; 
                app.ListBox_CH2.Items = current_items;
            case 2
                app.data_x_buffer3 = [app.data_x_buffer3, data_x];
                app.data_y_buffer3 = [app.data_y_buffer3, data_y];
                current_items = app.ListBox_CH3.Items;
                current_items{1} = pairs; 
                app.ListBox_CH3.Items = current_items;
            case 3
                app.data_x_buffer4 = [app.data_x_buffer4, data_x];
                app.data_y_buffer4 = [app.data_y_buffer4, data_y];
                current_items = app.ListBox_CH4.Items;
                current_items{1} = pairs; 
                app.ListBox_CH4.Items = current_items;
            case 4
                app.data_x_buffer5 = [app.data_x_buffer5, data_x];
                app.data_y_buffer5 = [app.data_y_buffer5, data_y];
                current_items = app.ListBox_CH5.Items;
                current_items{1} = pairs; 
                app.ListBox_CH5.Items = current_items;
            case 5
                app.data_x_buffer6 = [app.data_x_buffer6, data_x];
                app.data_y_buffer6 = [app.data_y_buffer6, data_y];
                current_items = app.ListBox_CH6.Items;
                current_items{1} = pairs; 
                app.ListBox_CH6.Items = current_items;
        end
    end
end

function receiveData(app)
        if app.serialObj.NumBytesAvailable > 0
        data = read(app.serialObj, app.serialObj.NumBytesAvailable, 'uint8'); 
        parseSerialData(app, data);
        end
end

function receiveDEBUG(app)
  
    if app.serialObj.NumBytesAvailable > 0

        data = read(app.serialObj, app.serialObj.NumBytesAvailable, 'uint8'); 
        if strcmp(app.ReceiveHEXSwitch.Value, 'On')
     
            hexStr = sprintf('%02X ', data);  

            current_items = app.InputdataListBox.Items;
            

            if isempty(current_items) || (numel(current_items) == 1 && strcmp(current_items, ''))
                current_items = cell(1, app.MAX_ITEMS);  
                current_items{1} = hexStr;          
                num_items = 1;                      
            else
                num_items = numel(current_items);  
                current_items(num_items+1:app.MAX_ITEMS) = cell(1, app.MAX_ITEMS - num_items); 
                current_items{num_items + 1} = hexStr;   
                num_items = num_items + 1;           
            end
            
         
            current_items = current_items(1:num_items);
            
         
            app.InputdataListBox.Items = current_items;
            scroll(app.InputdataListBox,'bottom');
            drawnow;
        else
 
            strData = char(data');  
            strData = reshape(strData, 1, []);  
           
                current_items = app.InputdataListBox.Items;
                
                
                if isempty(current_items) || (numel(current_items) == 1 && strcmp(current_items, ''))
                    current_items = cell(1, app.MAX_ITEMS);  
                    current_items{1} = strData;           
                    num_items = 1;                     
                else
                    num_items = numel(current_items);   
                    current_items(num_items+1:app.MAX_ITEMS) = cell(1, app.MAX_ITEMS - num_items); 
                    current_items{num_items + 1} = strData;   
                    num_items = num_items + 1;         
                end
                
               
                current_items = current_items(1:num_items);
                
               
                app.InputdataListBox.Items = current_items;
                scroll(app.InputdataListBox,'bottom');
                
                drawnow;
        end        
    end
    drawnow limitrate;
end



    end
    
    methods (Access = private)
        
        
function sendHexData(app, hexString)

    try
    
        hexData = uint8(sscanf(char(hexString), '%2x').');  
 
        if app.isConnected
            write(app.serialObj, hexData, 'uint8'); 
            disp("HEX data sent successfully.");
        else
            error("Serial port is not connected or invalid.");
        end
    catch ME
  
        uialert(app.UIFigure, ['Failed to send HEX data: ', ME.message], 'Send Error');
    end
end

function hexStr = convertToHex(~, value, bitSize)

    hexStr = dec2hex(value, bitSize / 4);  

    hexStr = reshape(hexStr, 2, []).';  
    hexStr = flipud(hexStr);           
    hexStr = hexStr.';                
    hexStr = hexStr(:).';              
end


function hexStr = floatToHex(~,value)
    littleEndianHex = typecast(single(value), 'uint32');
    
    littleEndianStr = dec2hex(littleEndianHex, 8);
    
    hexStr = littleEndianStr([7 8 5 6 3 4 1 2]);
end

    function setupTimer(app)
        app.plotTimer = timer('ExecutionMode', 'fixedRate', ...
                              'Period', 1, ...  
                              'TimerFcn', @(~,~) app.updatePlot());
    end
        
function updatePlot(app)
    if app.DEBUGSwitch.Value == "Off"
        if app.DEBUGSwitch.Value == "Off"
            scatter(app.UIAxes_1, app.data_x_buffer1, app.data_y_buffer1,5,"blue","filled");
            scatter(app.UIAxes_2, app.data_x_buffer2, app.data_y_buffer2,5,"red","filled");
            scatter(app.UIAxes_3, app.data_x_buffer3, app.data_y_buffer3,5,"black","filled");
            scatter(app.UIAxes_4, app.data_x_buffer4, app.data_y_buffer4,5,"green","filled");
            scatter(app.UIAxes_5, app.data_x_buffer5, app.data_y_buffer5,5,"cyan","filled");
            scatter(app.UIAxes_6, app.data_x_buffer6, app.data_y_buffer6,5,"magenta","filled");
        end
    drawnow;
    end
end

        
        
function filtered_data = lowPassFilter(~, data)

    fs = 1000; 
    cutoff_freq = 50; 
    [b, a] = butter(4, cutoff_freq / (fs / 2));
    
    filtered_data = filter(b, a, data);
end
    end
    
    

    % Callbacks that handle component events
    methods (Access = private)

        % Code that executes after component creation
        function startupFcn(app)
                        clc;
            for i = 1:28
                editFieldName = sprintf('param%dEditField', i);
                labelFieldName = sprintf('param%dEditFieldLabel', i);
                app.(editFieldName).Visible = 'off';
                app.(labelFieldName).Visible = 'off';
            end
        setupTimer(app);
            app.MODE_Value = 0;
            app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE';
            app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'HighE';
            app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'LowE';
            app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'FinalE';
            app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'direct';
            app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'ScanRate';
            app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'Segments';
            app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'SampleInt';
            app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'QuietTime';
        end

        % Close request function: UIFigure
        function UIFigureCloseRequest(app, event)
            delete(app)
            
        end

        % Button pushed function: SendButton
        function SendButtonPushed(app, event)
    if app.isConnected
        data = string(app.OutputdataTextArea.Value);
        if app.SendHEXSwitch.Value == "On"
            try
                hexData = uint8(sscanf(char(data), '%2x').'); 
                write(app.serialObj, hexData, 'uint8'); 
                disp("Data sent in HEX format."); 
            catch ME
                uialert(app.UIFigure, ['Failed to send data in HEX format: ', ME.message], 'Send Error');
            end
        else
            try
                write(app.serialObj, char(data), 'char');
                disp("Data sent as string."); 
            catch ME
              
                uialert(app.UIFigure, ['Failed to send data as string: ', ME.message], 'Send Error');
            end
        end
    else
        uialert(app.UIFigure, 'Serial port is not connected or invalid. Please connect to a valid port.', 'Connection Error');
    end

        end

        % Button pushed function: ClearButton
        function ClearButtonPushed(app, event)
                    app.InputdataListBox.Items = "";
                    drawnow;
        end

        % Button pushed function: SaveButton
        function SaveButtonPushed(app, event)
    [file, path] = uiputfile('*.txt', 'Save Data As');
    
    if ischar(file)
        fullPath = fullfile(path, file);
        
        data = app.InputdataListBox.Items;
        
        fid = fopen(fullPath, 'w');
        
        fprintf(fid, '%s\n', data{:});
        
        fclose(fid);
    end
        end

        % Button pushed function: StartAllButton
        function StartAllButtonPushed(app, event)
                setupTimer(app);
                    app.data_x_buffer1 = zeros(0, 0);
                    app.data_y_buffer1 = zeros(0, 0);
                    app.data_x_buffer2 = zeros(0, 0);
                    app.data_y_buffer2 = zeros(0, 0);
                    app.data_x_buffer3 = zeros(0, 0);
                    app.data_y_buffer3 = zeros(0, 0);
                    app.data_x_buffer4 = zeros(0, 0);
                    app.data_y_buffer4 = zeros(0, 0);
                    app.data_x_buffer5 = zeros(0, 0);
                    app.data_y_buffer5 = zeros(0, 0);
                    app.data_x_buffer6 = zeros(0, 0);
                    app.data_y_buffer6 = zeros(0, 0);
                app.isPolting = 1;
    hexString = "10000000 00000000 00000000 00000000 CDCC4CBE 3333333F CDCC4CBE CDCC4CBE 0000803F 0AD7233C 0000C040 6F12033B 0000A040 00002041 9A993141 33334341 CDCC5441 66666641 00007841 CDCC8441 9A998D41 66669641 33339F41 0000A041 CDCCA841 9A99B141 6666BA41 3333C341 0000CC41 CDCCD441 9A99DD41 6666E641";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopAllButton
        function StopAllButtonPushed(app, event)
            
                    app.isPolting = 0;
    hexString = "10000000 00000000 00000000 01000000 CDCC4CBE 3333333F CDCC4CBE CDCC4CBE 0000803F 0AD7233C 0000C040 6F12033B 0000A040 00002041 9A993141 33334341 CDCC5441 66666641 00007841 CDCC8441 9A998D41 66669641 33339F41 0000A041 CDCCA841 9A99B141 6666BA41 3333C341 0000CC41 CDCCD441 9A99DD41 6666E641";
    sendHexData(app, hexString);
        end

        % Button pushed function: ConnectButton
        function ConnectButtonPushed(app, event)
% Callback function for the Connect button
if app.isConnected && isvalid(app.serialObj)
        configureCallback(app.serialObj, "off"); 

        try
            delete(app.serialObj); 
        catch ME
        uialert(app.UIFigure, ['Unable to close serial port: ', ME.message], 'Connection Error');
        end
        if strcmp(app.plotTimer.Running, 'on')
        stop(app.plotTimer);
        end
        app.isConnected = false;
        app.serialObj = []; 
        app.ConnectButton.Text = 'Connect'; 
        app.ConnectLamp.Color = [1 0 0];
        disp("Disconnected");
else
    portName = app.serialDropDown.Value; 
    
    try
        app.serialObj = serialport(portName, 115200);
        
        if (app.DEBUGSwitch.Value == "On")
            configureCallback(app.serialObj, "terminator", @(~, ~) app.receiveDEBUG());
        else
            start(app.plotTimer);
            configureCallback(app.serialObj, "byte", 12, @(~, ~) app.receiveData());
        end
        app.isConnected = true;
        app.ConnectButton.Text = 'Disconnect'; 
        app.ConnectLamp.Color = [0 1 0];
        disp("Connected successfully"); 

    catch ME
        
        uialert(app.UIFigure, ['Unable to open serial port: ', ME.message], 'Connection Error');
        if isvalid(app.serialObj) 
            delete(app.serialObj); 
        end
        app.isConnected = false;
    end
end

 drawnow limitrate;

        end

        % Value changed function: ReceiveHEXSwitch
        function ReceiveHEXSwitchValueChanged(app, event)
    if strcmp(app.ReceiveHEXSwitch.Value, 'On')
        currentData = app.InputdataListBox.Items;
        hexData = cellfun(@(str) sprintf('%02X ', uint8(str)), currentData, 'UniformOutput', false);
        app.InputdataListBox.Items = hexData;
    else
        hexData = app.InputdataListBox.Items;
        try
            asciiData = cellfun(@(hexStr) char(uint8(sscanf(hexStr, '%2X')')), hexData, 'UniformOutput', false);
            app.InputdataListBox.Items = asciiData;
        catch
            app.InputdataListBox.Items = {'Invalid HEX format'};
        end
    end
        end

        % Value changed function: SendHEXSwitch
        function SendHEXSwitchValueChanged(app, event)
    if strcmp(app.SendHEXSwitch.Value, 'On')
        disp("Send mode set to HEX.");
    else
        disp("Send mode set to Text.");
    end
        end

        % Button pushed function: ParamSetButton
        function ParamSetButtonPushed(app, event)
    chnHex = convertToHex(app, app.CHN_Value, 32);
    modeHex = convertToHex(app, app.MODE_Value, 32);
    sensHex = convertToHex(app, app.SENS_Value, 32);
    
    cmdHex = "00000000";
    
    paramsHex = "";
    for i = 1:28
        paramFieldName = sprintf('param%dEditField', i);
        paramValue = app.(paramFieldName).Value; 
        paramHex = floatToHex(app, paramValue);   
        paramsHex = paramsHex + " " + paramHex;    
    end
    
    hexString = sprintf('%s %s %s %s%s', chnHex, modeHex, sensHex, cmdHex, paramsHex);
    
    app.OutputdataTextArea.Value = hexString;
    
    if app.isConnected
            try
                hexData = uint8(sscanf(char(hexString), '%2x').'); 
                write(app.serialObj, hexData, 'uint8');  
                disp("Parameters set successfully。"); 
            catch ME
                uialert(app.UIFigure, ['Failed to set parameters: ', ME.message], 'Send Error');
            end
    else
        uialert(app.UIFigure, 'Serial port is not connected or invalid. Please connect to a valid port.', 'Connection Error');
    end
        end

        % Value changed function: CHNDropDown
        function CHNDropDownValueChanged(app, event)
   value = app.CHNDropDown.Value;    
    switch value
        case 'CHN1'
            app.CHN_Value = 0;
        case 'CHN2'
            app.CHN_Value = 1;
        case 'CHN3'
            app.CHN_Value = 2;
        case 'CHN4'
            app.CHN_Value = 3;
        case 'CHN5'
            app.CHN_Value = 4;
        case 'CHN6'
            app.CHN_Value = 5;
        otherwise
            app.CHN_Value = 255;  
    end
            
        end

        % Value changed function: MODEDropDown
        function MODEDropDownValueChanged(app, event)
            value = app.MODEDropDown.Value;
            for i = 1:28
                editFieldName = sprintf('param%dEditField', i);
                labelFieldName = sprintf('param%dEditFieldLabel', i);
                app.(editFieldName).Visible = 'off';
                app.(editFieldName).Value = 0;
                app.(labelFieldName).Visible = 'off';
            end
switch value
    case 'CV'
        app.MODE_Value = 0;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = -0.2;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'HighE'; app.param2EditField.Value = 0.7;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'LowE'; app.param3EditField.Value = -0.2;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'FinalE'; app.param4EditField.Value = -0.2;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'direct'; app.param5EditField.Value = 1;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'ScanRate'; app.param6EditField.Value = 0.01;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'Segments'; app.param7EditField.Value = 6;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'SampleInt'; app.param8EditField.Value = 0.002;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'QuietTime'; app.param9EditField.Value = 5;
    
    case 'LSV'
        app.MODE_Value = 1;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = -0.2;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'ScanRate'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'SampleInt'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'QuietTime'; app.param5EditField.Value = 0;
    
    case 'SCV'
        app.MODE_Value = 2;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'Segments'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'QuietTime'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'IncrE'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'SampleWidth'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'StepPeriod'; app.param7EditField.Value = 0;
    
    case 'TAFEL'
        app.MODE_Value = 3;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'ScanRate'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'Segments'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'QuietTime'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'IncrE'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'HoldTime'; app.param7EditField.Value = 0;
    
    case 'CA'
        app.MODE_Value = 4;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'Steps'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'PulseWidth'; app.param5EditField.Value = 0;        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'SampleInt';app.param1EditField.Value = 0;
    case 'CC'
        app.MODE_Value = 5;
        % Parameter 1 to 8 configuration for 'CC'
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'HighE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'LowE'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'direct'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'QuietTime'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'Steps'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'PulseWidth'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'SampleInt'; app.param8EditField.Value = 0;
        
    case 'DPV'
        app.MODE_Value = 6;
        % Parameter 1 to 8 configuration for 'DPV'
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'IncrE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'SampleWidth'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'PulseWidth'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'Amplitude'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'PulsePeriod'; app.param8EditField.Value = 0;
    
    case 'NPV'
        app.MODE_Value = 7;
        % Parameter 1 to 7 configuration for 'NPV'
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'IncrE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'SampleWidth'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'PulseWidth'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'PulsePeriod'; app.param7EditField.Value = 0;
    
    case 'DNPV'
        app.MODE_Value = 8;
        % Parameter 1 to 9 configuration for 'DNPV'
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'IncrE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'SampleWidth'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'Amplitude'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'PulsePeriod'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'PulseWidth1'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'PulseWidth2'; app.param9EditField.Value = 0;
    
    case 'SWV'
        app.MODE_Value = 9;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0; 
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'IncrE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'Amplitude'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'Frequency'; app.param6EditField.Value = 0;
    
    case 'IT'
        app.MODE_Value = 10;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'QuietTime'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'SampleInt'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'RunTime'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'Scales'; app.param5EditField.Value = 0;
    
    case 'DPA'
        app.MODE_Value = 11;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'QuietTime'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'Scales'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'CleaningE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'CleaningT'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'PulseE1'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'PulseT1'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'PulseE2'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'PulseT2'; app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'Cycles'; app.param10EditField.Value = 0;
    
    case 'DDPA'
        app.MODE_Value = 12;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'QuietTime'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'Scales'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'CleaningE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'CleaningT'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'PulseE1'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'PulseT1'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'PulseE2'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'PulseT2'; app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'Cycles'; app.param10EditField.Value = 0;
        app.param11EditField.Visible = 1; app.param11EditFieldLabel.Visible = 1; app.param11EditFieldLabel.Text = 'CleaningE2'; app.param11EditField.Value = 0;
        app.param12EditField.Visible = 1; app.param12EditFieldLabel.Visible = 1; app.param12EditFieldLabel.Text = 'CleaningT2'; app.param12EditField.Value = 0;
        app.param13EditField.Visible = 1; app.param13EditFieldLabel.Visible = 1; app.param13EditFieldLabel.Text = 'PulseE3'; app.param13EditField.Value = 0;
        app.param14EditField.Visible = 1; app.param14EditFieldLabel.Visible = 1; app.param14EditFieldLabel.Text = 'PulseT3'; app.param14EditField.Value = 0;
        app.param15EditField.Visible = 1; app.param15EditFieldLabel.Visible = 1; app.param15EditFieldLabel.Text = 'PulseE4'; app.param15EditField.Value = 0;
        app.param16EditField.Visible = 1; app.param16EditFieldLabel.Visible = 1; app.param16EditFieldLabel.Text = 'PulseT4'; app.param16EditField.Value = 0;
    case 'TPA'
        app.MODE_Value = 13;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'FinalE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'QuietTime'; app.param3EditField.Value = 0; 
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'IncrE'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'Scales'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'E1'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'D1'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'E2'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'D2'; app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'Cycles'; app.param10EditField.Value = 0;
        app.param11EditField.Visible = 1; app.param11EditFieldLabel.Visible = 1; app.param11EditFieldLabel.Text = 'E3'; app.param11EditField.Value = 0;
        app.param12EditField.Visible = 1; app.param12EditFieldLabel.Visible = 1; app.param12EditFieldLabel.Text = 'D3'; app.param12EditField.Value = 0;       
    case 'IPAD'
        app.MODE_Value = 14;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'QuietTime'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'E1'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'T1'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'E2'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'T2'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'E3'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'T3'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'E4'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'T4'; app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'E5'; app.param10EditField.Value = 0;
        app.param11EditField.Visible = 1; app.param11EditFieldLabel.Visible = 1; app.param11EditFieldLabel.Text = 'T5'; app.param11EditField.Value = 0;
        app.param12EditField.Visible = 1; app.param12EditFieldLabel.Visible = 1; app.param12EditFieldLabel.Text = 'E6'; app.param12EditField.Value = 0;
        app.param13EditField.Visible = 1; app.param13EditFieldLabel.Visible = 1; app.param13EditFieldLabel.Text = 'T6'; app.param13EditField.Value = 0;
        app.param14EditField.Visible = 1; app.param14EditFieldLabel.Visible = 1; app.param14EditFieldLabel.Text = 'Cycles'; app.param14EditField.Value = 0;
    case 'SSF'
        app.MODE_Value = 15;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE0'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'InitE1'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'ScanRate1'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'FinalE1'; app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'InitE2'; app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'ScanRate2'; app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'FinalE2'; app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'InitE3'; app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'ScanRate3'; app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'FinalE3'; app.param10EditField.Value = 0;
        app.param11EditField.Visible = 1; app.param11EditFieldLabel.Visible = 1; app.param11EditFieldLabel.Text = 'InitE4'; app.param11EditField.Value = 0;
        app.param12EditField.Visible = 1; app.param12EditFieldLabel.Visible = 1; app.param12EditFieldLabel.Text = 'ScanRate4'; app.param12EditField.Value = 0;
        app.param13EditField.Visible = 1; app.param13EditFieldLabel.Visible = 1; app.param13EditFieldLabel.Text = 'FinalE4'; app.param13EditField.Value = 0;
        app.param14EditField.Visible = 1; app.param14EditFieldLabel.Visible = 1; app.param14EditFieldLabel.Text = 'InitE5'; app.param14EditField.Value = 0;
        app.param15EditField.Visible = 1; app.param15EditFieldLabel.Visible = 1; app.param15EditFieldLabel.Text = 'ScanRate5'; app.param15EditField.Value = 0;
        app.param16EditField.Visible = 1; app.param16EditFieldLabel.Visible = 1; app.param16EditFieldLabel.Text = 'FinalE5'; app.param16EditField.Value = 0;
        app.param17EditField.Visible = 1; app.param17EditFieldLabel.Visible = 1; app.param17EditFieldLabel.Text = 'InitE6'; app.param17EditField.Value = 0;
        app.param18EditField.Visible = 1; app.param18EditFieldLabel.Visible = 1; app.param18EditFieldLabel.Text = 'ScanRate6'; app.param18EditField.Value = 0;
        app.param19EditField.Visible = 1; app.param19EditFieldLabel.Visible = 1; app.param19EditFieldLabel.Text = 'FinalE6'; app.param19EditField.Value = 0;
        app.param20EditField.Visible = 1; app.param20EditFieldLabel.Visible = 1; app.param20EditFieldLabel.Text = 'QuietTime'; app.param20EditField.Value = 0;
        app.param21EditField.Visible = 1; app.param21EditFieldLabel.Visible = 1; app.param21EditFieldLabel.Text = 'E1'; app.param21EditField.Value = 0;
        app.param22EditField.Visible = 1; app.param22EditFieldLabel.Visible = 1; app.param22EditFieldLabel.Text = 'T1'; app.param22EditField.Value = 0;
        app.param23EditField.Visible = 1; app.param23EditFieldLabel.Visible = 1; app.param23EditFieldLabel.Text = 'E2'; app.param23EditField.Value = 0;
        app.param24EditField.Visible = 1; app.param24EditFieldLabel.Visible = 1; app.param24EditFieldLabel.Text = 'T2'; app.param24EditField.Value = 0;
        app.param25EditField.Visible = 1; app.param25EditFieldLabel.Visible = 1; app.param25EditFieldLabel.Text = 'E3'; app.param25EditField.Value = 0;
        app.param26EditField.Visible = 1; app.param26EditFieldLabel.Visible = 1; app.param26EditFieldLabel.Text = 'T3'; app.param26EditField.Value = 0;
        app.param27EditField.Visible = 1; app.param27EditFieldLabel.Visible = 1; app.param27EditFieldLabel.Text = 'E4'; app.param27EditField.Value = 0;
        app.param28EditField.Visible = 1; app.param28EditFieldLabel.Visible = 1; app.param28EditFieldLabel.Text = 'T4'; app.param28EditField.Value = 0;
        app.param29EditField.Visible = 1; app.param29EditFieldLabel.Visible = 1; app.param29EditFieldLabel.Text = 'E5'; app.param29EditField.Value = 0;
        app.param30EditField.Visible = 1; app.param30EditFieldLabel.Visible = 1; app.param30EditFieldLabel.Text = 'T5'; app.param30EditField.Value = 0;
        app.param31EditField.Visible = 1; app.param31EditFieldLabel.Visible = 1; app.param31EditFieldLabel.Text = 'E6'; app.param31EditField.Value = 0;
        app.param32EditField.Visible = 1; app.param32EditFieldLabel.Visible = 1; app.param32EditFieldLabel.Text = 'T6'; app.param32EditField.Value = 0;
        app.param33EditField.Visible = 1; app.param33EditFieldLabel.Visible = 1; app.param33EditFieldLabel.Text = 'SweepInt'; app.param33EditField.Value = 0;
        app.param34EditField.Visible = 1; app.param34EditFieldLabel.Visible = 1; app.param34EditFieldLabel.Text = 'StepInt'; app.param34EditField.Value = 0;
    case 'STEP'
        app.MODE_Value = 16;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'InitE';app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'QuietTime';app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'SampleInt';app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'E1';app.param4EditField.Value = 0;
        app.param5EditField.Visible = 1; app.param5EditFieldLabel.Visible = 1; app.param5EditFieldLabel.Text = 'T1';app.param5EditField.Value = 0;
        app.param6EditField.Visible = 1; app.param6EditFieldLabel.Visible = 1; app.param6EditFieldLabel.Text = 'E2';app.param6EditField.Value = 0;
        app.param7EditField.Visible = 1; app.param7EditFieldLabel.Visible = 1; app.param7EditFieldLabel.Text = 'T2';app.param7EditField.Value = 0;
        app.param8EditField.Visible = 1; app.param8EditFieldLabel.Visible = 1; app.param8EditFieldLabel.Text = 'E3';app.param8EditField.Value = 0;
        app.param9EditField.Visible = 1; app.param9EditFieldLabel.Visible = 1; app.param9EditFieldLabel.Text = 'T3';app.param9EditField.Value = 0;
        app.param10EditField.Visible = 1; app.param10EditFieldLabel.Visible = 1; app.param10EditFieldLabel.Text = 'E4';app.param10EditField.Value = 0;
        app.param11EditField.Visible = 1; app.param11EditFieldLabel.Visible = 1; app.param11EditFieldLabel.Text = 'T4';app.param11EditField.Value = 0;
        app.param12EditField.Visible = 1; app.param12EditFieldLabel.Visible = 1; app.param12EditFieldLabel.Text = 'E5';app.param12EditField.Value = 0;
        app.param13EditField.Visible = 1; app.param13EditFieldLabel.Visible = 1; app.param13EditFieldLabel.Text = 'T5';app.param13EditField.Value = 0;
        app.param14EditField.Visible = 1; app.param14EditFieldLabel.Visible = 1; app.param14EditFieldLabel.Text = 'E6';app.param14EditField.Value = 0;
        app.param15EditField.Visible = 1; app.param15EditFieldLabel.Visible = 1; app.param15EditFieldLabel.Text = 'T6';app.param15EditField.Value = 0;
        app.param16EditField.Visible = 1; app.param16EditFieldLabel.Visible = 1; app.param16EditFieldLabel.Text = 'E7';app.param16EditField.Value = 0;
        app.param17EditField.Visible = 1; app.param17EditFieldLabel.Visible = 1; app.param17EditFieldLabel.Text = 'T7';app.param17EditField.Value = 0;
        app.param18EditField.Visible = 1; app.param18EditFieldLabel.Visible = 1; app.param18EditFieldLabel.Text = 'E8';app.param18EditField.Value = 0;
        app.param19EditField.Visible = 1; app.param19EditFieldLabel.Visible = 1; app.param19EditFieldLabel.Text = 'T8';app.param19EditField.Value = 0;
        app.param20EditField.Visible = 1; app.param20EditFieldLabel.Visible = 1; app.param20EditFieldLabel.Text = 'E9';app.param20EditField.Value = 0;
        app.param21EditField.Visible = 1; app.param21EditFieldLabel.Visible = 1; app.param21EditFieldLabel.Text = 'T9';app.param21EditField.Value = 0;
        app.param22EditField.Visible = 1; app.param22EditFieldLabel.Visible = 1; app.param22EditFieldLabel.Text = 'E10';app.param22EditField.Value = 0;
        app.param23EditField.Visible = 1; app.param23EditFieldLabel.Visible = 1; app.param23EditFieldLabel.Text = 'T10';app.param23EditField.Value = 0;
        app.param24EditField.Visible = 1; app.param24EditFieldLabel.Visible = 1; app.param24EditFieldLabel.Text = 'E11';app.param24EditField.Value = 0;
        app.param25EditField.Visible = 1; app.param25EditFieldLabel.Visible = 1; app.param25EditFieldLabel.Text = 'T11';app.param25EditField.Value = 0;
        app.param26EditField.Visible = 1; app.param26EditFieldLabel.Visible = 1; app.param26EditFieldLabel.Text = 'E12';app.param26EditField.Value = 0;
        app.param27EditField.Visible = 1; app.param27EditFieldLabel.Visible = 1; app.param27EditFieldLabel.Text = 'T12';app.param27EditField.Value = 0;
        app.param28EditField.Visible = 1; app.param28EditFieldLabel.Visible = 1; app.param28EditFieldLabel.Text = 'Cycles';app.param28EditField.Value = 0;
    case 'OCPT'
        app.MODE_Value = 17;
        app.param1EditField.Visible = 1; app.param1EditFieldLabel.Visible = 1; app.param1EditFieldLabel.Text = 'HighE'; app.param1EditField.Value = 0;
        app.param2EditField.Visible = 1; app.param2EditFieldLabel.Visible = 1; app.param2EditFieldLabel.Text = 'LowE'; app.param2EditField.Value = 0;
        app.param3EditField.Visible = 1; app.param3EditFieldLabel.Visible = 1; app.param3EditFieldLabel.Text = 'SampleInt'; app.param3EditField.Value = 0;
        app.param4EditField.Visible = 1; app.param4EditFieldLabel.Visible = 1; app.param4EditFieldLabel.Text = 'RunTime'; app.param4EditField.Value = 0;
    case 'NONE'
        app.MODE_Value = 255;
    otherwise
        app.MODE_Value = 255;
end

        end

        % Value changed function: SENSDropDown
        function SENSDropDownValueChanged(app, event)
            value = app.SENSDropDown.Value;
    switch value
        case 'SENS1'
            app.SENS_Value = 0;
        case 'SENS2'
            app.SENS_Value = 1;
        case 'SENS3'
            app.SENS_Value = 2;
        case 'SENS4'
            app.SENS_Value = 3;
        otherwise
            app.SENS_Value = 255; 
    end
        end

        % Button pushed function: ClearPlotButton
        function ClearPlotButtonPushed(app, event)
            cla(app.UIAxes_1);  
            cla(app.UIAxes_2);
            cla(app.UIAxes_3);
            cla(app.UIAxes_4);
            cla(app.UIAxes_5);
            cla(app.UIAxes_6);
            app.data_x_buffer1 = zeros(0,0);
            app.data_y_buffer1 = zeros(0,0);
            app.data_x_buffer2 = zeros(0,0);
            app.data_y_buffer2 = zeros(0,0);
            app.data_x_buffer3 = zeros(0,0);
            app.data_y_buffer3 = zeros(0,0);
            app.data_x_buffer4 = zeros(0,0);
            app.data_y_buffer4 = zeros(0,0);
            app.data_x_buffer5 = zeros(0,0);
            app.data_y_buffer5 = zeros(0,0);
            app.data_x_buffer6 = zeros(0,0);
            app.data_y_buffer6 = zeros(0,0);
        end

        % Button pushed function: SearchButton
        function SearchButtonPushed(app, event)
            % Change button text to "Searching..." and disable it
            app.SearchButton.Text = 'Searching...';
            app.SearchButton.Enable = 'off';
            
            drawnow;
            
            % Get available serial ports
            ports = serialportlist("available");
            app.serialDropDown.Items = ports;
            
            % Check if there are any available ports
            if ~isempty(app.serialDropDown.Items)
                % Restore button text and enable it
                app.SearchButton.Text = 'Search';
                app.SearchButton.Enable = 'on';
            else
                % If no ports found, you may want to give some feedback to the user
                % For example, you can add a message or a different button state
                % Here is just an example of how to give feedback:
                uialert(app.UIFigure, 'No available serial ports found.', 'Warning');
                app.SearchButton.Text = 'Search';
                app.SearchButton.Enable = 'on';
            end
        end

        % Button pushed function: ClearTransButton
        function ClearTransButtonPushed(app, event)
            app.OutputdataTextArea.Value = ""; 
        end

        % Button pushed function: StartCHN1Button
        function StartCHN1ButtonPushed(app, event)
              
    app.isPolting = 1;
    hexString = "10000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN1Button
        function StopCHN1ButtonPushed(app, event)
             
    hexString = "10000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN1Button
        function PauseCHN1ButtonPushed(app, event)
                
    hexString = "10000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN1Button
        function ContinueCHN1ButtonPushed(app, event)

    hexString = "10000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StartCHN2Button
        function StartCHN2ButtonPushed(app, event)
              
    app.isPolting = 1;
    hexString = "20000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN2Button
        function StopCHN2ButtonPushed(app, event)
             
    hexString = "20000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN2Button
        function PauseCHN2ButtonPushed(app, event)
                
    hexString = "20000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN2Button
        function ContinueCHN2ButtonPushed(app, event)

    hexString = "20000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StartCHN3Button
        function StartCHN3ButtonPushed(app, event)
              
    app.isPolting = 1;
    hexString = "30000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN3Button
        function StopCHN3ButtonPushed(app, event)
             
    hexString = "30000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN3Button
        function PauseCHN3ButtonPushed(app, event)
            
    hexString = "30000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN3Button
        function ContinueCHN3ButtonPushed(app, event)

    hexString = "30000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StartCHN4Button
        function StartCHN4ButtonPushed(app, event)
              
    app.isPolting = 1;
    hexString = "40000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN4Button
        function StopCHN4ButtonPushed(app, event)
             
    hexString = "40000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN4Button
        function PauseCHN4ButtonPushed(app, event)
                
    hexString = "40000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN4Button
        function ContinueCHN4ButtonPushed(app, event)

    hexString = "40000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StartCHN5Button
        function StartCHN5ButtonPushed(app, event)
              
    app.isPolting = 1;
    hexString = "50000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN5Button
        function StopCHN5ButtonPushed(app, event)
             
    hexString = "50000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN5Button
        function PauseCHN5ButtonPushed(app, event)
                
    hexString = "50000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN5Button
        function ContinueCHN5ButtonPushed(app, event)

    hexString = "50000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StartCHN6Button
        function StartCHN6ButtonPushed(app, event)
              
                app.isPolting = 1;
    hexString = "60000000 00000000 00000000 03000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: StopCHN6Button
        function StopCHN6ButtonPushed(app, event)
             
    hexString = "60000000 00000000 00000000 02000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: PauseCHN6Button
        function PauseCHN6ButtonPushed(app, event)
                
    hexString = "60000000 00000000 00000000 04000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Button pushed function: ContinueCHN6Button
        function ContinueCHN6ButtonPushed(app, event)

    hexString = "60000000 00000000 00000000 05000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 ";
    sendHexData(app, hexString); 
        end

        % Value changed function: DEBUGSwitch
        function DEBUGSwitchValueChanged(app, event)
             if (app.DEBUGSwitch.Value == "On")
                    app.Panel1.Visible = 1;
            else
                    app.Panel1.Visible = 0;
            end
            if app.isConnected && isvalid(app.serialObj)  
                configureCallback(app.serialObj, "off"); 
                if (app.DEBUGSwitch.Value == "On")
                    stop(app.plotTimer);
                    configureCallback(app.serialObj, "terminator", @(~, ~) app.receiveDEBUG());
                else
                    start(app.plotTimer);
                    configureCallback(app.serialObj, "byte", 12, @(~, ~) app.receiveData());
                end
            end
%             app.InputdataListBox.Items = "";

            drawnow;
        end

        % Button pushed function: CH1Save
        function CH1SaveButtonPushed(app, event)

[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer1);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer1(i), app.data_y_buffer1(i));
    end
    
  
    fclose(fid);
end

        end

        % Button pushed function: CH2Save
        function CH2SaveButtonPushed(app, event)
            
[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer2);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer2(i), app.data_y_buffer2(i));
    end
    
  
    fclose(fid);
end

        end

        % Button pushed function: CH3Save
        function CH3SaveButtonPushed(app, event)
            
[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer3);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer3(i), app.data_y_buffer3(i));
    end
    
  
    fclose(fid);
end

        end

        % Button pushed function: CH4Save
        function CH4SaveButtonPushed(app, event)
            
[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer4);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer4(i), app.data_y_buffer4(i));
    end
    
  
    fclose(fid);
end

        end

        % Button pushed function: CH5Save
        function CH5SaveButtonPushed(app, event)
            
[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer5);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer5(i), app.data_y_buffer5(i));
    end
    
  
    fclose(fid);
end

        end

        % Button pushed function: CH6Save
        function CH6SaveButtonPushed(app, event)
            
[file, path] = uiputfile('*.txt', 'Save Data As');


if ischar(file)
    
    fullPath = fullfile(path, file);
    
    
    fid = fopen(fullPath, 'w');
    
    
    n = length(app.data_x_buffer6);
    
    
    for i = 1:n
       
        fprintf(fid, '%.3f, %.7f\n', app.data_x_buffer6(i), app.data_y_buffer6(i));
    end
    
  
    fclose(fid);
end

        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Color = [0.251 0.251 0.251];
            app.UIFigure.Position = [100 100 910 504];
            app.UIFigure.Name = 'MATLAB App';
            app.UIFigure.CloseRequestFcn = createCallbackFcn(app, @UIFigureCloseRequest, true);
            app.UIFigure.WindowState = 'maximized';

            % Create TabGroup
            app.TabGroup = uitabgroup(app.UIFigure);
            app.TabGroup.Position = [462 7 441 492];

            % Create Tab1
            app.Tab1 = uitab(app.TabGroup);
            app.Tab1.Title = 'CHN1';
            app.Tab1.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_1
            app.UIAxes_1 = uiaxes(app.Tab1);
            title(app.UIAxes_1, '')
            xlabel(app.UIAxes_1, '')
            ylabel(app.UIAxes_1, '')
            app.UIAxes_1.XColor = [0 0 0];
            app.UIAxes_1.YColor = [0 0 0];
            app.UIAxes_1.ZColor = [0 0 0];
            app.UIAxes_1.XGrid = 'on';
            app.UIAxes_1.YGrid = 'on';
            app.UIAxes_1.TitleFontWeight = 'bold';
            app.UIAxes_1.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_1.Position = [5 76 425 387];

            % Create StopCHN1Button
            app.StopCHN1Button = uibutton(app.Tab1, 'push');
            app.StopCHN1Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN1ButtonPushed, true);
            app.StopCHN1Button.BackgroundColor = [1 0 0];
            app.StopCHN1Button.FontColor = [1 1 1];
            app.StopCHN1Button.Position = [119 14 82 22];
            app.StopCHN1Button.Text = 'StopCHN1';

            % Create StartCHN1Button
            app.StartCHN1Button = uibutton(app.Tab1, 'push');
            app.StartCHN1Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN1ButtonPushed, true);
            app.StartCHN1Button.BackgroundColor = [0 1 0];
            app.StartCHN1Button.Position = [17 14 82 22];
            app.StartCHN1Button.Text = 'StartCHN1';

            % Create ContinueCHN1Button
            app.ContinueCHN1Button = uibutton(app.Tab1, 'push');
            app.ContinueCHN1Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN1ButtonPushed, true);
            app.ContinueCHN1Button.Position = [327 14 96 22];
            app.ContinueCHN1Button.Text = 'ContinueCHN1';

            % Create PauseCHN1Button
            app.PauseCHN1Button = uibutton(app.Tab1, 'push');
            app.PauseCHN1Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN1ButtonPushed, true);
            app.PauseCHN1Button.Position = [223 14 82 22];
            app.PauseCHN1Button.Text = 'PauseCHN1';

            % Create ListBox_CH1
            app.ListBox_CH1 = uilistbox(app.Tab1);
            app.ListBox_CH1.Items = {};
            app.ListBox_CH1.FontSize = 16;
            app.ListBox_CH1.FontColor = [1 1 1];
            app.ListBox_CH1.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH1.Position = [19 42 309 27];
            app.ListBox_CH1.Value = {};

            % Create CH1Save
            app.CH1Save = uibutton(app.Tab1, 'push');
            app.CH1Save.ButtonPushedFcn = createCallbackFcn(app, @CH1SaveButtonPushed, true);
            app.CH1Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH1Save.Position = [347 46 76 22];
            app.CH1Save.Text = 'Save';

            % Create CHN2Tab
            app.CHN2Tab = uitab(app.TabGroup);
            app.CHN2Tab.Title = 'CHN2';
            app.CHN2Tab.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_2
            app.UIAxes_2 = uiaxes(app.CHN2Tab);
            title(app.UIAxes_2, '')
            xlabel(app.UIAxes_2, 'X')
            ylabel(app.UIAxes_2, 'Y')
            app.UIAxes_2.XColor = [0 0 0];
            app.UIAxes_2.YColor = [0 0 0];
            app.UIAxes_2.ZColor = [0 0 0];
            app.UIAxes_2.XGrid = 'on';
            app.UIAxes_2.YGrid = 'on';
            app.UIAxes_2.TitleFontWeight = 'bold';
            app.UIAxes_2.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_2.Position = [5 76 425 387];

            % Create StopCHN2Button
            app.StopCHN2Button = uibutton(app.CHN2Tab, 'push');
            app.StopCHN2Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN2ButtonPushed, true);
            app.StopCHN2Button.BackgroundColor = [1 0 0];
            app.StopCHN2Button.FontColor = [1 1 1];
            app.StopCHN2Button.Position = [119 14 82 22];
            app.StopCHN2Button.Text = 'StopCHN2';

            % Create StartCHN2Button
            app.StartCHN2Button = uibutton(app.CHN2Tab, 'push');
            app.StartCHN2Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN2ButtonPushed, true);
            app.StartCHN2Button.BackgroundColor = [0 1 0];
            app.StartCHN2Button.Position = [17 14 82 22];
            app.StartCHN2Button.Text = 'StartCHN2';

            % Create ContinueCHN2Button
            app.ContinueCHN2Button = uibutton(app.CHN2Tab, 'push');
            app.ContinueCHN2Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN2ButtonPushed, true);
            app.ContinueCHN2Button.Position = [327 14 96 22];
            app.ContinueCHN2Button.Text = 'ContinueCHN2';

            % Create PauseCHN2Button
            app.PauseCHN2Button = uibutton(app.CHN2Tab, 'push');
            app.PauseCHN2Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN2ButtonPushed, true);
            app.PauseCHN2Button.Position = [223 14 82 22];
            app.PauseCHN2Button.Text = 'PauseCHN2';

            % Create ListBox_CH2
            app.ListBox_CH2 = uilistbox(app.CHN2Tab);
            app.ListBox_CH2.Items = {};
            app.ListBox_CH2.FontSize = 16;
            app.ListBox_CH2.FontColor = [1 1 1];
            app.ListBox_CH2.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH2.Position = [19 42 309 27];
            app.ListBox_CH2.Value = {};

            % Create CH2Save
            app.CH2Save = uibutton(app.CHN2Tab, 'push');
            app.CH2Save.ButtonPushedFcn = createCallbackFcn(app, @CH2SaveButtonPushed, true);
            app.CH2Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH2Save.Position = [347 46 76 22];
            app.CH2Save.Text = 'Save';

            % Create CHN3Tab
            app.CHN3Tab = uitab(app.TabGroup);
            app.CHN3Tab.Title = 'CHN3';
            app.CHN3Tab.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_3
            app.UIAxes_3 = uiaxes(app.CHN3Tab);
            title(app.UIAxes_3, '')
            xlabel(app.UIAxes_3, 'X')
            ylabel(app.UIAxes_3, 'Y')
            app.UIAxes_3.XGrid = 'on';
            app.UIAxes_3.YGrid = 'on';
            app.UIAxes_3.TitleFontWeight = 'bold';
            app.UIAxes_3.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_3.Position = [5 76 425 387];

            % Create StopCHN3Button
            app.StopCHN3Button = uibutton(app.CHN3Tab, 'push');
            app.StopCHN3Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN3ButtonPushed, true);
            app.StopCHN3Button.BackgroundColor = [1 0 0];
            app.StopCHN3Button.FontColor = [1 1 1];
            app.StopCHN3Button.Position = [119 14 82 22];
            app.StopCHN3Button.Text = 'StopCHN3';

            % Create StartCHN3Button
            app.StartCHN3Button = uibutton(app.CHN3Tab, 'push');
            app.StartCHN3Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN3ButtonPushed, true);
            app.StartCHN3Button.BackgroundColor = [0 1 0];
            app.StartCHN3Button.Position = [17 14 82 22];
            app.StartCHN3Button.Text = 'StartCHN3';

            % Create ContinueCHN3Button
            app.ContinueCHN3Button = uibutton(app.CHN3Tab, 'push');
            app.ContinueCHN3Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN3ButtonPushed, true);
            app.ContinueCHN3Button.Position = [327 14 96 22];
            app.ContinueCHN3Button.Text = 'ContinueCHN3';

            % Create PauseCHN3Button
            app.PauseCHN3Button = uibutton(app.CHN3Tab, 'push');
            app.PauseCHN3Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN3ButtonPushed, true);
            app.PauseCHN3Button.Position = [223 14 82 22];
            app.PauseCHN3Button.Text = 'PauseCHN3';

            % Create ListBox_CH3
            app.ListBox_CH3 = uilistbox(app.CHN3Tab);
            app.ListBox_CH3.Items = {};
            app.ListBox_CH3.FontSize = 16;
            app.ListBox_CH3.FontColor = [1 1 1];
            app.ListBox_CH3.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH3.Position = [19 42 309 27];
            app.ListBox_CH3.Value = {};

            % Create CH3Save
            app.CH3Save = uibutton(app.CHN3Tab, 'push');
            app.CH3Save.ButtonPushedFcn = createCallbackFcn(app, @CH3SaveButtonPushed, true);
            app.CH3Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH3Save.Position = [347 46 76 22];
            app.CH3Save.Text = 'Save';

            % Create CHN4Tab
            app.CHN4Tab = uitab(app.TabGroup);
            app.CHN4Tab.Title = 'CHN4';
            app.CHN4Tab.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_4
            app.UIAxes_4 = uiaxes(app.CHN4Tab);
            title(app.UIAxes_4, '')
            xlabel(app.UIAxes_4, 'X')
            ylabel(app.UIAxes_4, 'Y')
            app.UIAxes_4.XGrid = 'on';
            app.UIAxes_4.YGrid = 'on';
            app.UIAxes_4.TitleFontWeight = 'bold';
            app.UIAxes_4.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_4.Position = [5 76 425 387];

            % Create StopCHN4Button
            app.StopCHN4Button = uibutton(app.CHN4Tab, 'push');
            app.StopCHN4Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN4ButtonPushed, true);
            app.StopCHN4Button.BackgroundColor = [1 0 0];
            app.StopCHN4Button.FontColor = [1 1 1];
            app.StopCHN4Button.Position = [119 14 82 22];
            app.StopCHN4Button.Text = 'StopCHN4';

            % Create StartCHN4Button
            app.StartCHN4Button = uibutton(app.CHN4Tab, 'push');
            app.StartCHN4Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN4ButtonPushed, true);
            app.StartCHN4Button.BackgroundColor = [0 1 0];
            app.StartCHN4Button.Position = [17 14 82 22];
            app.StartCHN4Button.Text = 'StartCHN4';

            % Create ContinueCHN4Button
            app.ContinueCHN4Button = uibutton(app.CHN4Tab, 'push');
            app.ContinueCHN4Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN4ButtonPushed, true);
            app.ContinueCHN4Button.Position = [327 14 96 22];
            app.ContinueCHN4Button.Text = 'ContinueCHN4';

            % Create PauseCHN4Button
            app.PauseCHN4Button = uibutton(app.CHN4Tab, 'push');
            app.PauseCHN4Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN4ButtonPushed, true);
            app.PauseCHN4Button.Position = [223 14 82 22];
            app.PauseCHN4Button.Text = 'PauseCHN4';

            % Create ListBox_CH4
            app.ListBox_CH4 = uilistbox(app.CHN4Tab);
            app.ListBox_CH4.Items = {};
            app.ListBox_CH4.FontSize = 16;
            app.ListBox_CH4.FontColor = [1 1 1];
            app.ListBox_CH4.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH4.Position = [19 42 309 27];
            app.ListBox_CH4.Value = {};

            % Create CH4Save
            app.CH4Save = uibutton(app.CHN4Tab, 'push');
            app.CH4Save.ButtonPushedFcn = createCallbackFcn(app, @CH4SaveButtonPushed, true);
            app.CH4Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH4Save.Position = [347 46 76 22];
            app.CH4Save.Text = 'Save';

            % Create CHN5Tab
            app.CHN5Tab = uitab(app.TabGroup);
            app.CHN5Tab.Title = 'CHN5';
            app.CHN5Tab.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_5
            app.UIAxes_5 = uiaxes(app.CHN5Tab);
            title(app.UIAxes_5, '')
            xlabel(app.UIAxes_5, 'X')
            ylabel(app.UIAxes_5, 'Y')
            app.UIAxes_5.XGrid = 'on';
            app.UIAxes_5.YGrid = 'on';
            app.UIAxes_5.TitleFontWeight = 'bold';
            app.UIAxes_5.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_5.Position = [5 76 425 387];

            % Create StopCHN5Button
            app.StopCHN5Button = uibutton(app.CHN5Tab, 'push');
            app.StopCHN5Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN5ButtonPushed, true);
            app.StopCHN5Button.BackgroundColor = [1 0 0];
            app.StopCHN5Button.FontColor = [1 1 1];
            app.StopCHN5Button.Position = [119 14 82 22];
            app.StopCHN5Button.Text = 'StopCHN5';

            % Create StartCHN5Button
            app.StartCHN5Button = uibutton(app.CHN5Tab, 'push');
            app.StartCHN5Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN5ButtonPushed, true);
            app.StartCHN5Button.BackgroundColor = [0 1 0];
            app.StartCHN5Button.Position = [17 14 82 22];
            app.StartCHN5Button.Text = 'StartCHN5';

            % Create ContinueCHN5Button
            app.ContinueCHN5Button = uibutton(app.CHN5Tab, 'push');
            app.ContinueCHN5Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN5ButtonPushed, true);
            app.ContinueCHN5Button.Position = [327 14 96 22];
            app.ContinueCHN5Button.Text = 'ContinueCHN5';

            % Create PauseCHN5Button
            app.PauseCHN5Button = uibutton(app.CHN5Tab, 'push');
            app.PauseCHN5Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN5ButtonPushed, true);
            app.PauseCHN5Button.Position = [223 14 82 22];
            app.PauseCHN5Button.Text = 'PauseCHN5';

            % Create ListBox_CH5
            app.ListBox_CH5 = uilistbox(app.CHN5Tab);
            app.ListBox_CH5.Items = {};
            app.ListBox_CH5.FontSize = 16;
            app.ListBox_CH5.FontColor = [1 1 1];
            app.ListBox_CH5.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH5.Position = [17 42 311 27];
            app.ListBox_CH5.Value = {};

            % Create CH5Save
            app.CH5Save = uibutton(app.CHN5Tab, 'push');
            app.CH5Save.ButtonPushedFcn = createCallbackFcn(app, @CH5SaveButtonPushed, true);
            app.CH5Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH5Save.Position = [347 46 76 22];
            app.CH5Save.Text = 'Save';

            % Create CHN6Tab
            app.CHN6Tab = uitab(app.TabGroup);
            app.CHN6Tab.Title = 'CHN6';
            app.CHN6Tab.BackgroundColor = [0.651 0.651 0.651];

            % Create UIAxes_6
            app.UIAxes_6 = uiaxes(app.CHN6Tab);
            title(app.UIAxes_6, '')
            xlabel(app.UIAxes_6, 'X')
            ylabel(app.UIAxes_6, 'Y')
            app.UIAxes_6.XGrid = 'on';
            app.UIAxes_6.YGrid = 'on';
            app.UIAxes_6.TitleFontWeight = 'bold';
            app.UIAxes_6.BackgroundColor = [0.8 0.8 0.8];
            app.UIAxes_6.Position = [5 76 425 387];

            % Create StopCHN6Button
            app.StopCHN6Button = uibutton(app.CHN6Tab, 'push');
            app.StopCHN6Button.ButtonPushedFcn = createCallbackFcn(app, @StopCHN6ButtonPushed, true);
            app.StopCHN6Button.BackgroundColor = [1 0 0];
            app.StopCHN6Button.FontColor = [1 1 1];
            app.StopCHN6Button.Position = [119 14 82 22];
            app.StopCHN6Button.Text = 'StopCHN6';

            % Create StartCHN6Button
            app.StartCHN6Button = uibutton(app.CHN6Tab, 'push');
            app.StartCHN6Button.ButtonPushedFcn = createCallbackFcn(app, @StartCHN6ButtonPushed, true);
            app.StartCHN6Button.BackgroundColor = [0 1 0];
            app.StartCHN6Button.Position = [17 14 82 22];
            app.StartCHN6Button.Text = 'StartCHN6';

            % Create ContinueCHN6Button
            app.ContinueCHN6Button = uibutton(app.CHN6Tab, 'push');
            app.ContinueCHN6Button.ButtonPushedFcn = createCallbackFcn(app, @ContinueCHN6ButtonPushed, true);
            app.ContinueCHN6Button.BackgroundColor = [1 1 1];
            app.ContinueCHN6Button.Position = [327 14 96 22];
            app.ContinueCHN6Button.Text = 'ContinueCHN6';

            % Create PauseCHN6Button
            app.PauseCHN6Button = uibutton(app.CHN6Tab, 'push');
            app.PauseCHN6Button.ButtonPushedFcn = createCallbackFcn(app, @PauseCHN6ButtonPushed, true);
            app.PauseCHN6Button.BackgroundColor = [1 1 1];
            app.PauseCHN6Button.Position = [223 14 82 22];
            app.PauseCHN6Button.Text = 'PauseCHN6';

            % Create ListBox_CH6
            app.ListBox_CH6 = uilistbox(app.CHN6Tab);
            app.ListBox_CH6.Items = {};
            app.ListBox_CH6.FontSize = 16;
            app.ListBox_CH6.FontColor = [1 1 1];
            app.ListBox_CH6.BackgroundColor = [0.651 0.651 0.651];
            app.ListBox_CH6.Position = [19 42 309 27];
            app.ListBox_CH6.Value = {};

            % Create CH6Save
            app.CH6Save = uibutton(app.CHN6Tab, 'push');
            app.CH6Save.ButtonPushedFcn = createCallbackFcn(app, @CH6SaveButtonPushed, true);
            app.CH6Save.BackgroundColor = [0.8 0.8 0.8];
            app.CH6Save.Position = [347 46 76 22];
            app.CH6Save.Text = 'Save';

            % Create Panel_2
            app.Panel_2 = uipanel(app.UIFigure);
            app.Panel_2.ForegroundColor = [1 1 1];
            app.Panel_2.BackgroundColor = [0.251 0.251 0.251];
            app.Panel_2.Position = [7 7 456 492];

            % Create CHNDropDownLabel
            app.CHNDropDownLabel = uilabel(app.Panel_2);
            app.CHNDropDownLabel.HorizontalAlignment = 'right';
            app.CHNDropDownLabel.FontWeight = 'bold';
            app.CHNDropDownLabel.FontColor = [0.851 0.3255 0.098];
            app.CHNDropDownLabel.Position = [20 396 31 22];
            app.CHNDropDownLabel.Text = 'CHN';

            % Create CHNDropDown
            app.CHNDropDown = uidropdown(app.Panel_2);
            app.CHNDropDown.Items = {'CHN1', 'CHN2', 'CHN3', 'CHN4', 'CHN5', 'CHN6'};
            app.CHNDropDown.ValueChangedFcn = createCallbackFcn(app, @CHNDropDownValueChanged, true);
            app.CHNDropDown.FontColor = [0.902 0.902 0.902];
            app.CHNDropDown.BackgroundColor = [0.149 0.149 0.149];
            app.CHNDropDown.Position = [60 396 82 22];
            app.CHNDropDown.Value = 'CHN1';

            % Create MODEDropDownLabel
            app.MODEDropDownLabel = uilabel(app.Panel_2);
            app.MODEDropDownLabel.HorizontalAlignment = 'right';
            app.MODEDropDownLabel.FontWeight = 'bold';
            app.MODEDropDownLabel.FontColor = [0.851 0.3255 0.098];
            app.MODEDropDownLabel.Position = [161 396 41 22];
            app.MODEDropDownLabel.Text = 'MODE';

            % Create MODEDropDown
            app.MODEDropDown = uidropdown(app.Panel_2);
            app.MODEDropDown.Items = {'CV', 'LSV', 'SCV', 'TAFEL', 'CA', 'CC', 'DPV', 'NPV', 'DNPV', 'SWV', 'IT', 'DPA', 'DDPA', 'TPA', 'IPAD', 'SSF', 'STEP', 'OCPT', 'NONE'};
            app.MODEDropDown.ValueChangedFcn = createCallbackFcn(app, @MODEDropDownValueChanged, true);
            app.MODEDropDown.FontColor = [0.902 0.902 0.902];
            app.MODEDropDown.BackgroundColor = [0.149 0.149 0.149];
            app.MODEDropDown.Position = [207 396 84 22];
            app.MODEDropDown.Value = 'CV';

            % Create param1EditFieldLabel
            app.param1EditFieldLabel = uilabel(app.Panel_2);
            app.param1EditFieldLabel.FontSize = 10;
            app.param1EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param1EditFieldLabel.Position = [19 283 70 22];
            app.param1EditFieldLabel.Text = 'param1';

            % Create param1EditField
            app.param1EditField = uieditfield(app.Panel_2, 'numeric');
            app.param1EditField.HandleVisibility = 'off';
            app.param1EditField.FontSize = 4;
            app.param1EditField.FontColor = [0.902 0.902 0.902];
            app.param1EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param1EditField.Position = [19 262 91 22];

            % Create param2EditFieldLabel
            app.param2EditFieldLabel = uilabel(app.Panel_2);
            app.param2EditFieldLabel.FontSize = 10;
            app.param2EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param2EditFieldLabel.Position = [127 283 74 22];
            app.param2EditFieldLabel.Text = 'param2';

            % Create param2EditField
            app.param2EditField = uieditfield(app.Panel_2, 'numeric');
            app.param2EditField.HandleVisibility = 'off';
            app.param2EditField.FontSize = 4;
            app.param2EditField.FontColor = [0.902 0.902 0.902];
            app.param2EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param2EditField.Position = [130 262 92 22];

            % Create param3EditFieldLabel
            app.param3EditFieldLabel = uilabel(app.Panel_2);
            app.param3EditFieldLabel.FontSize = 10;
            app.param3EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param3EditFieldLabel.Position = [237 283 72 22];
            app.param3EditFieldLabel.Text = 'param3';

            % Create param3EditField
            app.param3EditField = uieditfield(app.Panel_2, 'numeric');
            app.param3EditField.HandleVisibility = 'off';
            app.param3EditField.FontSize = 4;
            app.param3EditField.FontColor = [0.902 0.902 0.902];
            app.param3EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param3EditField.Position = [238 262 93 22];

            % Create param4EditFieldLabel
            app.param4EditFieldLabel = uilabel(app.Panel_2);
            app.param4EditFieldLabel.FontSize = 10;
            app.param4EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param4EditFieldLabel.Position = [345 283 70 22];
            app.param4EditFieldLabel.Text = 'param4';

            % Create param4EditField
            app.param4EditField = uieditfield(app.Panel_2, 'numeric');
            app.param4EditField.HandleVisibility = 'off';
            app.param4EditField.FontSize = 4;
            app.param4EditField.FontColor = [0.902 0.902 0.902];
            app.param4EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param4EditField.Position = [344 262 91 22];

            % Create SENSDropDownLabel
            app.SENSDropDownLabel = uilabel(app.Panel_2);
            app.SENSDropDownLabel.HorizontalAlignment = 'right';
            app.SENSDropDownLabel.FontWeight = 'bold';
            app.SENSDropDownLabel.FontColor = [0.851 0.3255 0.098];
            app.SENSDropDownLabel.Position = [303 396 38 22];
            app.SENSDropDownLabel.Text = 'SENS';

            % Create SENSDropDown
            app.SENSDropDown = uidropdown(app.Panel_2);
            app.SENSDropDown.Items = {'SENS1', 'SENS2', 'SENS3', 'SENS4'};
            app.SENSDropDown.ValueChangedFcn = createCallbackFcn(app, @SENSDropDownValueChanged, true);
            app.SENSDropDown.FontColor = [0.9412 0.9412 0.9412];
            app.SENSDropDown.BackgroundColor = [0.149 0.149 0.149];
            app.SENSDropDown.Position = [346 396 82 22];
            app.SENSDropDown.Value = 'SENS1';

            % Create ParamSetButton
            app.ParamSetButton = uibutton(app.Panel_2, 'push');
            app.ParamSetButton.ButtonPushedFcn = createCallbackFcn(app, @ParamSetButtonPushed, true);
            app.ParamSetButton.BackgroundColor = [0.149 0.149 0.149];
            app.ParamSetButton.FontSize = 16;
            app.ParamSetButton.FontWeight = 'bold';
            app.ParamSetButton.FontColor = [0.902 0.902 0.902];
            app.ParamSetButton.Position = [11 347 129 32];
            app.ParamSetButton.Text = 'ParamSet';

            % Create StartAllButton
            app.StartAllButton = uibutton(app.Panel_2, 'push');
            app.StartAllButton.ButtonPushedFcn = createCallbackFcn(app, @StartAllButtonPushed, true);
            app.StartAllButton.BackgroundColor = [0.149 0.149 0.149];
            app.StartAllButton.FontSize = 16;
            app.StartAllButton.FontWeight = 'bold';
            app.StartAllButton.FontColor = [0 1 0];
            app.StartAllButton.Position = [162 348 131 31];
            app.StartAllButton.Text = 'StartAll';

            % Create StopAllButton
            app.StopAllButton = uibutton(app.Panel_2, 'push');
            app.StopAllButton.ButtonPushedFcn = createCallbackFcn(app, @StopAllButtonPushed, true);
            app.StopAllButton.BackgroundColor = [0.149 0.149 0.149];
            app.StopAllButton.FontSize = 16;
            app.StopAllButton.FontWeight = 'bold';
            app.StopAllButton.FontColor = [1 0 0];
            app.StopAllButton.Position = [315 348 131 31];
            app.StopAllButton.Text = 'StopAll';

            % Create ConnectButton
            app.ConnectButton = uibutton(app.Panel_2, 'push');
            app.ConnectButton.ButtonPushedFcn = createCallbackFcn(app, @ConnectButtonPushed, true);
            app.ConnectButton.BackgroundColor = [0.149 0.149 0.149];
            app.ConnectButton.FontColor = [1 1 1];
            app.ConnectButton.Position = [260 436 83 26];
            app.ConnectButton.Text = 'Connect';

            % Create serialDropDown
            app.serialDropDown = uidropdown(app.Panel_2);
            app.serialDropDown.Items = {'COM9'};
            app.serialDropDown.FontColor = [1 1 1];
            app.serialDropDown.BackgroundColor = [0.149 0.149 0.149];
            app.serialDropDown.Position = [96 436 112 26];
            app.serialDropDown.Value = 'COM9';

            % Create SearchButton
            app.SearchButton = uibutton(app.Panel_2, 'push');
            app.SearchButton.ButtonPushedFcn = createCallbackFcn(app, @SearchButtonPushed, true);
            app.SearchButton.BackgroundColor = [0.149 0.149 0.149];
            app.SearchButton.FontColor = [1 1 1];
            app.SearchButton.Position = [8 436 82 26];
            app.SearchButton.Text = 'Search';

            % Create ConnectLamp
            app.ConnectLamp = uilamp(app.Panel_2);
            app.ConnectLamp.Position = [243 444 11 11];
            app.ConnectLamp.Color = [1 0 0];

            % Create DEBUGSwitchLabel
            app.DEBUGSwitchLabel = uilabel(app.Panel_2);
            app.DEBUGSwitchLabel.HorizontalAlignment = 'center';
            app.DEBUGSwitchLabel.FontSize = 14;
            app.DEBUGSwitchLabel.FontColor = [0.902 0.902 0.902];
            app.DEBUGSwitchLabel.Position = [375 458 55 22];
            app.DEBUGSwitchLabel.Text = 'DEBUG';

            % Create DEBUGSwitch
            app.DEBUGSwitch = uiswitch(app.Panel_2, 'slider');
            app.DEBUGSwitch.ValueChangedFcn = createCallbackFcn(app, @DEBUGSwitchValueChanged, true);
            app.DEBUGSwitch.FontColor = [0.902 0.902 0.902];
            app.DEBUGSwitch.Position = [379 436 45 20];

            % Create ParametersLabel
            app.ParametersLabel = uilabel(app.Panel_2);
            app.ParametersLabel.FontColor = [1 1 1];
            app.ParametersLabel.Position = [20 304 80 22];
            app.ParametersLabel.Text = 'Parameters：';

            % Create Button
            app.Button = uibutton(app.Panel_2, 'state');
            app.Button.Text = '';
            app.Button.BackgroundColor = [0.149 0.149 0.149];
            app.Button.Position = [1 326 453 10];

            % Create param5EditFieldLabel
            app.param5EditFieldLabel = uilabel(app.Panel_2);
            app.param5EditFieldLabel.FontSize = 10;
            app.param5EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param5EditFieldLabel.Position = [20 241 71 22];
            app.param5EditFieldLabel.Text = 'param5';

            % Create param5EditField
            app.param5EditField = uieditfield(app.Panel_2, 'numeric');
            app.param5EditField.HandleVisibility = 'off';
            app.param5EditField.FontSize = 4;
            app.param5EditField.FontColor = [0.902 0.902 0.902];
            app.param5EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param5EditField.Position = [19 220 91 22];

            % Create param6EditFieldLabel
            app.param6EditFieldLabel = uilabel(app.Panel_2);
            app.param6EditFieldLabel.FontSize = 10;
            app.param6EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param6EditFieldLabel.Position = [127 239 74 22];
            app.param6EditFieldLabel.Text = 'param6';

            % Create param6EditField
            app.param6EditField = uieditfield(app.Panel_2, 'numeric');
            app.param6EditField.HandleVisibility = 'off';
            app.param6EditField.FontSize = 4;
            app.param6EditField.FontColor = [0.902 0.902 0.902];
            app.param6EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param6EditField.Position = [130 220 91 22];

            % Create param7EditFieldLabel
            app.param7EditFieldLabel = uilabel(app.Panel_2);
            app.param7EditFieldLabel.FontSize = 10;
            app.param7EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param7EditFieldLabel.Position = [237 239 72 22];
            app.param7EditFieldLabel.Text = 'param7';

            % Create param7EditField
            app.param7EditField = uieditfield(app.Panel_2, 'numeric');
            app.param7EditField.HandleVisibility = 'off';
            app.param7EditField.FontSize = 4;
            app.param7EditField.FontColor = [0.902 0.902 0.902];
            app.param7EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param7EditField.Position = [238 220 93 22];

            % Create param8EditFieldLabel
            app.param8EditFieldLabel = uilabel(app.Panel_2);
            app.param8EditFieldLabel.FontSize = 10;
            app.param8EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param8EditFieldLabel.Position = [345 239 70 22];
            app.param8EditFieldLabel.Text = 'param8';

            % Create param8EditField
            app.param8EditField = uieditfield(app.Panel_2, 'numeric');
            app.param8EditField.HandleVisibility = 'off';
            app.param8EditField.FontSize = 4;
            app.param8EditField.FontColor = [0.902 0.902 0.902];
            app.param8EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param8EditField.Position = [344 220 91 22];

            % Create param9EditFieldLabel
            app.param9EditFieldLabel = uilabel(app.Panel_2);
            app.param9EditFieldLabel.FontSize = 10;
            app.param9EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param9EditFieldLabel.Position = [19 199 71 22];
            app.param9EditFieldLabel.Text = 'param9';

            % Create param9EditField
            app.param9EditField = uieditfield(app.Panel_2, 'numeric');
            app.param9EditField.HandleVisibility = 'off';
            app.param9EditField.FontSize = 4;
            app.param9EditField.FontColor = [0.902 0.902 0.902];
            app.param9EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param9EditField.Position = [19 180 91 22];

            % Create param10EditFieldLabel
            app.param10EditFieldLabel = uilabel(app.Panel_2);
            app.param10EditFieldLabel.FontSize = 10;
            app.param10EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param10EditFieldLabel.Position = [130 201 74 22];
            app.param10EditFieldLabel.Text = 'param10';

            % Create param10EditField
            app.param10EditField = uieditfield(app.Panel_2, 'numeric');
            app.param10EditField.HandleVisibility = 'off';
            app.param10EditField.FontSize = 4;
            app.param10EditField.FontColor = [0.902 0.902 0.902];
            app.param10EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param10EditField.Position = [130 180 91 22];

            % Create param11EditFieldLabel
            app.param11EditFieldLabel = uilabel(app.Panel_2);
            app.param11EditFieldLabel.FontSize = 10;
            app.param11EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param11EditFieldLabel.Position = [239 199 72 22];
            app.param11EditFieldLabel.Text = 'param11';

            % Create param11EditField
            app.param11EditField = uieditfield(app.Panel_2, 'numeric');
            app.param11EditField.HandleVisibility = 'off';
            app.param11EditField.FontSize = 4;
            app.param11EditField.FontColor = [0.902 0.902 0.902];
            app.param11EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param11EditField.Position = [238 178 93 22];

            % Create param12EditFieldLabel
            app.param12EditFieldLabel = uilabel(app.Panel_2);
            app.param12EditFieldLabel.FontSize = 10;
            app.param12EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param12EditFieldLabel.Position = [347 199 70 22];
            app.param12EditFieldLabel.Text = 'param12';

            % Create param12EditField
            app.param12EditField = uieditfield(app.Panel_2, 'numeric');
            app.param12EditField.HandleVisibility = 'off';
            app.param12EditField.FontSize = 4;
            app.param12EditField.FontColor = [0.902 0.902 0.902];
            app.param12EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param12EditField.Position = [344 179 91 22];

            % Create param13EditFieldLabel
            app.param13EditFieldLabel = uilabel(app.Panel_2);
            app.param13EditFieldLabel.FontSize = 10;
            app.param13EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param13EditFieldLabel.Position = [20 159 71 22];
            app.param13EditFieldLabel.Text = 'param13';

            % Create param13EditField
            app.param13EditField = uieditfield(app.Panel_2, 'numeric');
            app.param13EditField.HandleVisibility = 'off';
            app.param13EditField.FontSize = 4;
            app.param13EditField.FontColor = [0.902 0.902 0.902];
            app.param13EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param13EditField.Position = [20 139 91 22];

            % Create param14EditFieldLabel
            app.param14EditFieldLabel = uilabel(app.Panel_2);
            app.param14EditFieldLabel.FontSize = 10;
            app.param14EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param14EditFieldLabel.Position = [127 157 74 22];
            app.param14EditFieldLabel.Text = 'param14';

            % Create param14EditField
            app.param14EditField = uieditfield(app.Panel_2, 'numeric');
            app.param14EditField.HandleVisibility = 'off';
            app.param14EditField.FontSize = 4;
            app.param14EditField.FontColor = [0.902 0.902 0.902];
            app.param14EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param14EditField.Position = [130 137 91 22];

            % Create param15EditFieldLabel
            app.param15EditFieldLabel = uilabel(app.Panel_2);
            app.param15EditFieldLabel.FontSize = 10;
            app.param15EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param15EditFieldLabel.Position = [241 159 72 22];
            app.param15EditFieldLabel.Text = 'param15';

            % Create param15EditField
            app.param15EditField = uieditfield(app.Panel_2, 'numeric');
            app.param15EditField.HandleVisibility = 'off';
            app.param15EditField.FontSize = 4;
            app.param15EditField.FontColor = [0.902 0.902 0.902];
            app.param15EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param15EditField.Position = [238 137 93 22];

            % Create param16EditFieldLabel
            app.param16EditFieldLabel = uilabel(app.Panel_2);
            app.param16EditFieldLabel.FontSize = 10;
            app.param16EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param16EditFieldLabel.Position = [345 157 70 22];
            app.param16EditFieldLabel.Text = 'param16';

            % Create param16EditField
            app.param16EditField = uieditfield(app.Panel_2, 'numeric');
            app.param16EditField.HandleVisibility = 'off';
            app.param16EditField.FontSize = 4;
            app.param16EditField.FontColor = [0.902 0.902 0.902];
            app.param16EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param16EditField.Position = [344 137 91 22];

            % Create param17EditFieldLabel
            app.param17EditFieldLabel = uilabel(app.Panel_2);
            app.param17EditFieldLabel.FontSize = 10;
            app.param17EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param17EditFieldLabel.Position = [21 118 72 22];
            app.param17EditFieldLabel.Text = 'param17';

            % Create param17EditField
            app.param17EditField = uieditfield(app.Panel_2, 'numeric');
            app.param17EditField.HandleVisibility = 'off';
            app.param17EditField.FontSize = 4;
            app.param17EditField.FontColor = [0.902 0.902 0.902];
            app.param17EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param17EditField.Position = [20 96 90 22];

            % Create param18EditFieldLabel
            app.param18EditFieldLabel = uilabel(app.Panel_2);
            app.param18EditFieldLabel.FontSize = 10;
            app.param18EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param18EditFieldLabel.Position = [132 117 74 22];
            app.param18EditFieldLabel.Text = 'param18';

            % Create param18EditField
            app.param18EditField = uieditfield(app.Panel_2, 'numeric');
            app.param18EditField.HandleVisibility = 'off';
            app.param18EditField.FontSize = 4;
            app.param18EditField.FontColor = [0.902 0.902 0.902];
            app.param18EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param18EditField.Position = [130 95 91 22];

            % Create param19EditFieldLabel
            app.param19EditFieldLabel = uilabel(app.Panel_2);
            app.param19EditFieldLabel.FontSize = 10;
            app.param19EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param19EditFieldLabel.Position = [238 117 72 22];
            app.param19EditFieldLabel.Text = 'param19';

            % Create param19EditField
            app.param19EditField = uieditfield(app.Panel_2, 'numeric');
            app.param19EditField.HandleVisibility = 'off';
            app.param19EditField.FontSize = 4;
            app.param19EditField.FontColor = [0.902 0.902 0.902];
            app.param19EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param19EditField.Position = [238 96 93 22];

            % Create param20EditFieldLabel
            app.param20EditFieldLabel = uilabel(app.Panel_2);
            app.param20EditFieldLabel.FontSize = 10;
            app.param20EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param20EditFieldLabel.Position = [347 116 70 22];
            app.param20EditFieldLabel.Text = 'param20';

            % Create param20EditField
            app.param20EditField = uieditfield(app.Panel_2, 'numeric');
            app.param20EditField.HandleVisibility = 'off';
            app.param20EditField.FontSize = 4;
            app.param20EditField.FontColor = [0.902 0.902 0.902];
            app.param20EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param20EditField.Position = [345 94 91 22];

            % Create param21EditFieldLabel
            app.param21EditFieldLabel = uilabel(app.Panel_2);
            app.param21EditFieldLabel.FontSize = 10;
            app.param21EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param21EditFieldLabel.Position = [22 76 72 22];
            app.param21EditFieldLabel.Text = 'param21';

            % Create param21EditField
            app.param21EditField = uieditfield(app.Panel_2, 'numeric');
            app.param21EditField.HandleVisibility = 'off';
            app.param21EditField.FontSize = 4;
            app.param21EditField.FontColor = [0.902 0.902 0.902];
            app.param21EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param21EditField.Position = [21 54 90 22];

            % Create param22EditFieldLabel
            app.param22EditFieldLabel = uilabel(app.Panel_2);
            app.param22EditFieldLabel.FontSize = 10;
            app.param22EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param22EditFieldLabel.Position = [130 75 74 22];
            app.param22EditFieldLabel.Text = 'param22';

            % Create param22EditField
            app.param22EditField = uieditfield(app.Panel_2, 'numeric');
            app.param22EditField.HandleVisibility = 'off';
            app.param22EditField.FontSize = 4;
            app.param22EditField.FontColor = [0.902 0.902 0.902];
            app.param22EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param22EditField.Position = [129 54 91 22];

            % Create param23EditFieldLabel
            app.param23EditFieldLabel = uilabel(app.Panel_2);
            app.param23EditFieldLabel.FontSize = 10;
            app.param23EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param23EditFieldLabel.Position = [241 76 72 22];
            app.param23EditFieldLabel.Text = 'param23';

            % Create param23EditField
            app.param23EditField = uieditfield(app.Panel_2, 'numeric');
            app.param23EditField.HandleVisibility = 'off';
            app.param23EditField.FontSize = 4;
            app.param23EditField.FontColor = [0.902 0.902 0.902];
            app.param23EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param23EditField.Position = [239 54 93 22];

            % Create param24EditFieldLabel
            app.param24EditFieldLabel = uilabel(app.Panel_2);
            app.param24EditFieldLabel.FontSize = 10;
            app.param24EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param24EditFieldLabel.Position = [346 75 70 22];
            app.param24EditFieldLabel.Text = 'param24';

            % Create param24EditField
            app.param24EditField = uieditfield(app.Panel_2, 'numeric');
            app.param24EditField.HandleVisibility = 'off';
            app.param24EditField.FontSize = 4;
            app.param24EditField.FontColor = [0.902 0.902 0.902];
            app.param24EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param24EditField.Position = [345 54 91 22];

            % Create param25EditFieldLabel
            app.param25EditFieldLabel = uilabel(app.Panel_2);
            app.param25EditFieldLabel.FontSize = 10;
            app.param25EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param25EditFieldLabel.Position = [21 33 72 22];
            app.param25EditFieldLabel.Text = 'param25';

            % Create param25EditField
            app.param25EditField = uieditfield(app.Panel_2, 'numeric');
            app.param25EditField.HandleVisibility = 'off';
            app.param25EditField.FontSize = 4;
            app.param25EditField.FontColor = [0.902 0.902 0.902];
            app.param25EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param25EditField.Position = [21 11 90 22];

            % Create param26EditFieldLabel
            app.param26EditFieldLabel = uilabel(app.Panel_2);
            app.param26EditFieldLabel.FontSize = 10;
            app.param26EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param26EditFieldLabel.Position = [128 31 74 22];
            app.param26EditFieldLabel.Text = 'param26';

            % Create param26EditField
            app.param26EditField = uieditfield(app.Panel_2, 'numeric');
            app.param26EditField.HandleVisibility = 'off';
            app.param26EditField.FontSize = 4;
            app.param26EditField.FontColor = [0.902 0.902 0.902];
            app.param26EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param26EditField.Position = [130 10 91 22];

            % Create param27EditFieldLabel
            app.param27EditFieldLabel = uilabel(app.Panel_2);
            app.param27EditFieldLabel.FontSize = 10;
            app.param27EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param27EditFieldLabel.Position = [238 32 72 22];
            app.param27EditFieldLabel.Text = 'param27';

            % Create param27EditField
            app.param27EditField = uieditfield(app.Panel_2, 'numeric');
            app.param27EditField.HandleVisibility = 'off';
            app.param27EditField.FontSize = 4;
            app.param27EditField.FontColor = [0.902 0.902 0.902];
            app.param27EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param27EditField.Position = [240 10 93 22];

            % Create param28EditFieldLabel
            app.param28EditFieldLabel = uilabel(app.Panel_2);
            app.param28EditFieldLabel.FontSize = 10;
            app.param28EditFieldLabel.FontColor = [0.9412 0.9412 0.9412];
            app.param28EditFieldLabel.Position = [346 32 70 22];
            app.param28EditFieldLabel.Text = 'param28';

            % Create param28EditField
            app.param28EditField = uieditfield(app.Panel_2, 'numeric');
            app.param28EditField.HandleVisibility = 'off';
            app.param28EditField.FontSize = 4;
            app.param28EditField.FontColor = [0.902 0.902 0.902];
            app.param28EditField.BackgroundColor = [0.149 0.149 0.149];
            app.param28EditField.Position = [346 10 91 22];

            % Create Panel1
            app.Panel1 = uipanel(app.Panel_2);
            app.Panel1.BorderType = 'none';
            app.Panel1.Visible = 'off';
            app.Panel1.BackgroundColor = [0.251 0.251 0.251];
            app.Panel1.Position = [4 1 447 431];

            % Create InputdataListBoxLabel
            app.InputdataListBoxLabel = uilabel(app.Panel1);
            app.InputdataListBoxLabel.FontColor = [0.051 0.902 0.149];
            app.InputdataListBoxLabel.Position = [5 396 89 22];
            app.InputdataListBoxLabel.Text = 'Input data';

            % Create InputdataListBox
            app.InputdataListBox = uilistbox(app.Panel1);
            app.InputdataListBox.Items = {};
            app.InputdataListBox.FontColor = [1 1 1];
            app.InputdataListBox.BackgroundColor = [0.149 0.149 0.149];
            app.InputdataListBox.Position = [3 177 345 220];
            app.InputdataListBox.Value = {};

            % Create ClearButton
            app.ClearButton = uibutton(app.Panel1, 'push');
            app.ClearButton.ButtonPushedFcn = createCallbackFcn(app, @ClearButtonPushed, true);
            app.ClearButton.BackgroundColor = [0.149 0.149 0.149];
            app.ClearButton.FontColor = [0.9412 0.9412 0.9412];
            app.ClearButton.Position = [365 331 76 22];
            app.ClearButton.Text = 'Clear';

            % Create SaveButton
            app.SaveButton = uibutton(app.Panel1, 'push');
            app.SaveButton.ButtonPushedFcn = createCallbackFcn(app, @SaveButtonPushed, true);
            app.SaveButton.BackgroundColor = [0.149 0.149 0.149];
            app.SaveButton.FontColor = [0.9412 0.9412 0.9412];
            app.SaveButton.Position = [365 274 76 22];
            app.SaveButton.Text = 'Save';

            % Create ReceiveHEXSwitchLabel
            app.ReceiveHEXSwitchLabel = uilabel(app.Panel1);
            app.ReceiveHEXSwitchLabel.HorizontalAlignment = 'center';
            app.ReceiveHEXSwitchLabel.FontColor = [0.9412 0.9412 0.9412];
            app.ReceiveHEXSwitchLabel.Position = [365 229 77 22];
            app.ReceiveHEXSwitchLabel.Text = 'Receive HEX';

            % Create ReceiveHEXSwitch
            app.ReceiveHEXSwitch = uiswitch(app.Panel1, 'slider');
            app.ReceiveHEXSwitch.ValueChangedFcn = createCallbackFcn(app, @ReceiveHEXSwitchValueChanged, true);
            app.ReceiveHEXSwitch.FontColor = [0.9412 0.9412 0.9412];
            app.ReceiveHEXSwitch.Position = [379 208 45 20];

            % Create SendButton
            app.SendButton = uibutton(app.Panel1, 'push');
            app.SendButton.ButtonPushedFcn = createCallbackFcn(app, @SendButtonPushed, true);
            app.SendButton.BackgroundColor = [0.149 0.149 0.149];
            app.SendButton.FontColor = [0.9412 0.9412 0.9412];
            app.SendButton.Position = [365 104 82 22];
            app.SendButton.Text = 'Send';

            % Create OutputdataTextArea
            app.OutputdataTextArea = uitextarea(app.Panel1);
            app.OutputdataTextArea.FontColor = [1 1 1];
            app.OutputdataTextArea.BackgroundColor = [0.149 0.149 0.149];
            app.OutputdataTextArea.Position = [2 6 346 120];
            app.OutputdataTextArea.Value = {'00000000 00000000 00000000 00000000 9A9999BE 3333333F 9A9999BE 9A9999BE 0000803F 0AD7A33C 00008040 6F12033B 0000A040 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000'};

            % Create ClearTransButton
            app.ClearTransButton = uibutton(app.Panel1, 'push');
            app.ClearTransButton.ButtonPushedFcn = createCallbackFcn(app, @ClearTransButtonPushed, true);
            app.ClearTransButton.BackgroundColor = [0.149 0.149 0.149];
            app.ClearTransButton.FontColor = [0.9412 0.9412 0.9412];
            app.ClearTransButton.Position = [364 6 80 22];
            app.ClearTransButton.Text = 'ClearTrans';

            % Create SendHEXSwitchLabel
            app.SendHEXSwitchLabel = uilabel(app.Panel1);
            app.SendHEXSwitchLabel.HorizontalAlignment = 'center';
            app.SendHEXSwitchLabel.FontColor = [0.9412 0.9412 0.9412];
            app.SendHEXSwitchLabel.Position = [368 69 71 22];
            app.SendHEXSwitchLabel.Text = 'Send HEX';

            % Create SendHEXSwitch
            app.SendHEXSwitch = uiswitch(app.Panel1, 'slider');
            app.SendHEXSwitch.ValueChangedFcn = createCallbackFcn(app, @SendHEXSwitchValueChanged, true);
            app.SendHEXSwitch.FontColor = [0.9412 0.9412 0.9412];
            app.SendHEXSwitch.Position = [380 47 45 20];
            app.SendHEXSwitch.Value = 'On';

            % Create ClearPlotButton
            app.ClearPlotButton = uibutton(app.Panel1, 'push');
            app.ClearPlotButton.ButtonPushedFcn = createCallbackFcn(app, @ClearPlotButtonPushed, true);
            app.ClearPlotButton.BackgroundColor = [0.149 0.149 0.149];
            app.ClearPlotButton.FontColor = [0.9412 0.9412 0.9412];
            app.ClearPlotButton.Position = [365 300 77 22];
            app.ClearPlotButton.Text = 'ClearPlot';

            % Create OutputdataTextAreaLabel
            app.OutputdataTextAreaLabel = uilabel(app.Panel1);
            app.OutputdataTextAreaLabel.FontColor = [0.9882 0.3137 0.2784];
            app.OutputdataTextAreaLabel.Position = [5 125 92 22];
            app.OutputdataTextAreaLabel.Text = 'Output data';

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = EprobeUART

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            % Execute the startup function
            runStartupFcn(app, @startupFcn)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end