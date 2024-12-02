fileID = fopen('input/day02.in', 'r');

valids = 0;
while ~feof(fileID)
    line = fgetl(fileID);
    parts = strsplit(strtrim(line), ' ');
    x = str2double(parts);
    dx = diff(x);
    incValid = all(dx>=1 & dx<=3,2);
    decValid = all(dx<=-1 & dx >= -3,2);
    if(incValid || decValid)
        valids = valids + 1;
    end
end
fprintf('Number of valid reports %d\n',valids);
fclose(fileID);