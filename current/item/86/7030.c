
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8609);
        set_picid_2(8609);

        set_level(30);
        set_value(17000);
        set_max_lasting(4999);
        set("cp", 50);
        set("pp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
