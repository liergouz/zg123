
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("ˮ������");
        set_picid_1(8610);
        set_picid_2(8610);

        set_level(65);
        set_value(38000);
        set_max_lasting(7999);
        set("cp", 0);
        set("pp", 65);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ˮ������";
}
