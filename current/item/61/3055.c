
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�ɱ���ȹ");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(24500);
        set_max_lasting(18099);
        set("dp", 137);
        set("pp", 79);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// ��������ȡ����
string get_desc()
{
        return "�ɱ���ȹ";
}
