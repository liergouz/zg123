
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8711);
        set_picid_2(8711);

        set_level(30);
        set_value(5000);
        set_max_lasting(7599);
        set("dp", 33);
        set("pp", 18);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
