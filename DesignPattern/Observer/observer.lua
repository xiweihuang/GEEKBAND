--[[
	观察者模式，lua实现
]]

s_observerArr = {}

-- 注册观察者
local function registerObserver(object, callBack, eventKey)
	if not s_observerArr[eventKey] then
		s_observerArr[eventKey] = {}
	end
	s_observerArr[eventKey][object] = callBack
end

-- 注销观察者
local function unRegisterObserver(object, eventKey)
	if s_observerArr[eventKey] and s_observerArr[eventKey][object] then
		s_observerArr[eventKey][object] = nil
	end
end


-- 发送消息
local function postNotification(eventKey, extendData)
	for k,v in pairs(s_observerArr[eventKey] or {}) do
		v(extendData)
	end
end


-- progressBar
local function setProgressValue(progress, value)
	print(string.format("进度%.2f", value/20.0))
	progress.value = value
end

-- fileSplitter
local function fileSplit(fileSplitter)
	for i=1, fileSplitter.fileNum do
		-- onProgress(i)
		postNotification("s_notif_split", i)
	end
end

-- main test
ProgressBar = {
	value = 0
}

FileSplitter = {
	fileNum = 20
}

local function onCallback(data)
	setProgressValue(ProgressBar, data)
end

registerObserver(ProgressBar, onCallback, "s_notif_split")

-- test = {}
-- local function output()
-- 	print("...jdfjls")
-- end
-- registerObserver(test, output, "s_notif_split")
-- unRegisterObserver(test, "s_notif_split")


fileSplit(FileSplitter)




