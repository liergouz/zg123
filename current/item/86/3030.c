
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8603);
        set_picid_2(8603);

        set_level(30);
        set_value(13500);
        set_max_lasting(6999);
        set("cp", 0);
        set("pp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
