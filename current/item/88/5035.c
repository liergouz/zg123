
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(35);
        set_value(5700);
        set_max_lasting(5399);
        set("dp", 9);
        set("sp", 13);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
