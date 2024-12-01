% Open the file and read it line by line
fileID = fopen('input/day01.txt', 'r');

lefties = [];
righties = [];

% Read input
while ~feof(fileID)
    line = fgetl(fileID);
    
    parts = strsplit(strtrim(line), ' ');
    lefties = [lefties, str2double(parts{1})];
    righties = [righties, str2double(parts{2})];
end

% Process
result = 0
for l = lefties
    result = result +  sum(righties == l)*l;
end
disp(result)
fclose(fileID);