
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ˮЬ");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(30);
        set_value(3500);
        set_max_lasting(6099);
        set("dp", 8);
        set("sp", 22);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ˮЬ";
}
