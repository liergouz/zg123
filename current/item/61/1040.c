
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(40);
        set_value(12500);
        set_max_lasting(13599);
        set("dp", 99);
        set("pp", 60);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "����ȹ";
}
