
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ˮȹ");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(30);
        set_value(6000);
        set_max_lasting(9099);
        set("dp", 67);
        set("pp", 39);

        setup();

        set_gender(2);
        set_armor_code(22);
}

// ��������ȡ����
string get_desc()
{
        return "��ˮȹ";
}
