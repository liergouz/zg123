
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(60000);
        set_max_lasting(42799);
        set("dp", 205);
        set("pp", 165);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
