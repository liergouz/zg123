
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(100);
        set_value(22500);
        set_max_lasting(13899);
        set("dp", 103);
        set("pp", 88);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
