# -*- coding: utf-8 -*-


import telebot
import random
from telebot import types

# Загружаем список интересных фактов
# Загружаем список поговорок
f = open('thinks.txt', 'r')
thinks = f.read()
f.close()
thinks = thinks.split("\n")
thinks1 = list()
num = 0
while num < len(thinks) - 1 :
    param = thinks[num].split(",")[1]
    if param[0] == "0" :
        thinks1.append(thinks[num].split(",")[0])
    num = num + 1
    # print(thinks1)

# Создаем бота
bot = telebot.TeleBot('5338252088:AAHwFIZoNPfiYyBzbcUzH9KsCYhxXam5Pp8')
# Команда start
@bot.message_handler(commands=["hello"])
def start(m, res=False):        
        # Добавляем две кнопки
        markup=types.ReplyKeyboardMarkup(resize_keyboard=True)
        num = 0
        while num < len(thinks1):
            print(thinks1[num])
            markup.add(types.KeyboardButton(thinks1[num]))
            num = num + 1
        bot.send_message(m.chat.id, 'выберите время: ',  reply_markup=markup)

# Получение сообщений от юзера
@bot.message_handler(content_types=["text"])

# можно добавить набивку в скоуп нужного времени
def handle_text(message):
    # Если юзер прислал 1, выдаем ему случайный факт
    
    # f = open('text.txt', 'a')
    # f.write('+'+ message.text.strip() + '\n')
    # f.close()

    old_line = message.text.strip() + ',0' + '\n'
    new_line = message.text.strip() + ',1' + '\n'

    # Read in the file
    file = open('file.txt', 'r')
    filedata = file.read()
    file.close


    # Replace the target string
    filedata = filedata.replace(old_line, new_line)

    # Write the file out again
    file = open('file.txt', 'w')
    file.write(filedata)
    file.close

    if message.text.strip() == 'Факт' :
            answer = random.choice(facts)
    # Если юзер прислал 2, выдаем умную мысль
    elif message.text.strip() == 'Поговорка':
            answer = random.choice(thinks)
    # Отсылаем юзеру сообщение в его чат
    bot.send_message(message.chat.id, thinks)
# Запускаем бота

bot.polling(none_stop=True, interval=0)
