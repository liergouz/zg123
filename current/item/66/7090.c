
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("ڤ���ñ");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(90);
        set_value(40000);
        set_max_lasting(9099);
        set("dp", 61);
        set("pp", 109);

        setup();

        set_gender(2);
        set_head_code(56);
}

// ��������ȡ����
string get_desc()
{
        return "ڤ���ñ";
}
