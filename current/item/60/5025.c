
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("�ط���");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3500);
        set_max_lasting(5499);
        set("dp", 43);
        set("pp", 67);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// ��������ȡ����
string get_desc()
{
        return "�ط���";
}
