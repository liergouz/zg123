
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ս��ñ");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(60);
        set_value(15500);
        set_max_lasting(10299);
        set("dp", 80);
        set("pp", 34);

        setup();

        set_gender(1);
        set_head_code(44);
}

// ��������ȡ����
string get_desc()
{
        return "ս��ñ";
}
